-- set minimum xmake version
set_xmakever("3.0.0")

-- set project constants
set_project("commonlibsf")
set_arch("x64")
set_languages("c++23")
set_warnings("allextra")
set_encodings("utf-8")

-- add common rules
add_rules("mode.debug", "mode.releasedbg")
add_rules("plugin.vsxmake.autoupdate")

-- include subprojects
includes("lib/commonlib-shared")

-- define targets
target("commonlibsf", function()
    -- set target kind
    set_kind("static")

    -- set build by default
    set_default(os.scriptdir() == os.projectdir())

    -- add packages
    add_deps("commonlib-shared", { public = true })

    -- add source files
    add_files("src/**.cpp")

    -- add header files
    add_includedirs("include", { public = true })
    add_headerfiles(
        "include/(RE/**.h)",
        "include/(SFSE/**.h)"
    )

    -- set precompiled header
    set_pcxxheader("include/SFSE/Impl/PCH.h")
end)

rule("commonlibsf.plugin", function()
    add_deps("commonlib.plugin")

    on_load(function(target)
        target:data_set("commonlib.plugin.config", target:extraconf("rules", "commonlibsf.plugin"))
        target:data_set("commonlib.plugin.package", { prefixdir = "Data" })
    end)

    on_config(function(target)
        target:add("deps", "commonlibsf")

        target:add("configfiles", path.join(os.scriptdir(), "res/commonlibsf-plugin.cpp.in"))
        target:add("files", path.join(target:configdir(), "commonlibsf-plugin.cpp"))

        local conf = target:extraconf("rules", "commonlibsf.plugin")
        if conf.options then
            if conf.options.sig_scanning then
                conf.options.address_library = false
            else
                conf.options.sig_scanning = false
                if conf.options.address_library == nil then
                    conf.options.address_library = true
                end
            end
            if conf.options.no_struct_use then
                conf.options.layout_dependent = false
            else
                conf.options.no_struct_use = false
                if conf.options.layout_dependent == nil then
                    conf.options.layout_dependent = true
                end
            end
        else
            conf.options = {
                sig_scanning = false,
                address_library = true,
                no_struct_use = false,
                layout_dependent = true
            }
        end

        target:set("configvar", "COMMONLIBSF_OPTION_SIG_SCANNING", tostring(conf.options.sig_scanning))
        target:set("configvar", "COMMONLIBSF_OPTION_ADDRESS_LIBRARY", tostring(conf.options.address_library))
        target:set("configvar", "COMMONLIBSF_OPTION_NO_STRUCT_USE", tostring(conf.options.no_struct_use))
        target:set("configvar", "COMMONLIBSF_OPTION_LAYOUT_DEPENDENT", tostring(conf.options.layout_dependent))

        if os.getenv("XSE_SF_MODS_PATH") then
            target:set("installdir", path.join(os.getenv("XSE_SF_MODS_PATH"), target:name()))
        elseif os.getenv("XSE_SF_GAME_PATH") then
            target:set("installdir", path.join(os.getenv("XSE_SF_GAME_PATH"), "Data"))
        end

        target:add("installfiles", target:targetfile(), { prefixdir = "SFSE/Plugins" })
        target:add("installfiles", target:symbolfile(), { prefixdir = "SFSE/Plugins" })
    end)
end)

rule("commonlibsf.archive", function()
    add_deps("commonlib.archive")

    on_load(function(target)
        target:data_set("commonlib.archive.config", target:extraconf("rules", "commonlibsf.archive"))
        target:data_set("commonlib.archive.format", "-sf1" )
        target:data_set("commonlib.archive.extension", ".ba2")
        target:data_set("commonlib.archive.suffix", " - Main")
    end)
end)

rule("commonlibsf.ddsarchive", function()
    add_deps("commonlib.archive")

    on_load(function(target)
        target:data_set("commonlib.archive.config", target:extraconf("rules", "commonlibsf.archive"))
        target:data_set("commonlib.archive.format", "-sf1dds" )
        target:data_set("commonlib.archive.extension", ".ba2")
        target:data_set("commonlib.archive.suffix", " - Textures")
    end)
end)

rule("commonlibsf.papyrus", function()
    add_deps("commonlib.papyrus")

    on_load(function(target)
        target:data_set("commonlib.papyrus.config", target:extraconf("rules", "commonlibsf.papyrus"))
        target:data_set("commonlib.papyrus.game", "starfield" )
        target:data_set("commonlib.papyrus.gamevar", "XSE_SF_GAME_PATH")
        target:data_set("commonlib.papyrus.defaults", { "Data/Scripts/Source" } )
        target:data_set("commonlib.papyrus.flags", "Starfield_Papyrus_Flags.flg")
    end)
end)
