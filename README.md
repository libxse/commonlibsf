# CommonLibSF

### Requirements
* [XMake](https://xmake.io) [3.0.0+]
* C++23 Compiler (MSVC or Clang-CL)

## Getting Started
```bat
git clone --recurse-submodules https://github.com/libxse/commonlibsf
cd commonlibsf
```

### Build
To build the project, run the following command:
```bat
xmake build
```

> ***Note:*** *This will generate a `build/windows/` directory in the **project's root directory** with the build output.*

### Project Generation (Optional)
If you use Visual Studio, run the following command:
```bat
xmake project -k vsxmake
```

> ***Note:*** *This will generate a `vsxmakeXXXX/` directory in the **project's root directory** using the latest version of Visual Studio installed on the system.*

**Alternatively**, if you do not use Visual Studio, you can generate a `compile_commands.json` file for use with a laguage server like clangd in any code editor that supports it, like vscode:
```bat
xmake project -k compile_commands
```

> ***Note:*** *You must have a language server extension installed to make use of this file. I recommend `clangd`. Do not have more than one installed at a time as they will conflict with each other. I also recommend installing the `xmake` extension if available to make building the project easier.*

## Notes

CommonLibSF is intended to replace SFSE as a static dependency. However, the runtime component of SFSE is still required.

## License

[GPL-3.0-or-later][LICENSE] WITH [Modding Exception AND GPL-3.0 Linking Exception (with Corresponding Source)](EXCEPTIONS).

Specifically, the **Modded Code** is Starfield (and its variants) and **Modding Libraries** include [SFSE](https://sfse.silverlock.org/) ([GitHub](https://github.com/ianpatt/sfse)).

It is recommended to read the [FSF FAQ](https://www.gnu.org/licenses/gpl-faq.en.html) for a full explanation on what this license requires.

The main requirement of this license is: if you link your mod against CommonLibSF, and you distribute the binaries for that mod, you must also distribute the source code under the same license as CommonLibSF along with the source code for any other libraries you link against, with the exception of the Modded Code and Modding Libraries defined above.

## Contributors

<!--CONTRIBUTORS_BEGIN--><table><tr>
  <td align="center">
    <a href="https://github.com/ThirdEyeSqueegee" title="Angad">
      <img src="https://avatars.githubusercontent.com/u/66992519?v=4" width="50;" alt="Angad"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/gottyduke" title="DK">
      <img src="https://avatars.githubusercontent.com/u/35783662?v=4" width="50;" alt="DK"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/powerof3" title="powerof3">
      <img src="https://avatars.githubusercontent.com/u/32599957?v=4" width="50;" alt="powerof3"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/qudix" title="qudix">
      <img src="https://avatars.githubusercontent.com/u/17361645?v=4" width="50;" alt="qudix"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/shad0wshayd3" title="shad0wshayd3">
      <img src="https://avatars.githubusercontent.com/u/2724172?v=4" width="50;" alt="shad0wshayd3"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/nikitalita" title="Nikita">
      <img src="https://avatars.githubusercontent.com/u/69168929?v=4" width="50;" alt="Nikita"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/TommInfinite" title="TommInfinite">
      <img src="https://avatars.githubusercontent.com/u/81481291?v=4" width="50;" alt="TommInfinite"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/Deweh" title="V">
      <img src="https://avatars.githubusercontent.com/u/76853940?v=4" width="50;" alt="V"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/BrodyHiggerson" title="BrodyHiggerson">
      <img src="https://avatars.githubusercontent.com/u/7245990?v=4" width="50;" alt="BrodyHiggerson"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/shadeMe" title="Madeesh Kannan">
      <img src="https://avatars.githubusercontent.com/u/214450?v=4" width="50;" alt="Madeesh Kannan"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/alandtse" title="Alan Tse">
      <img src="https://avatars.githubusercontent.com/u/7086117?v=4" width="50;" alt="Alan Tse"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/FlayaN" title="Flayan">
      <img src="https://avatars.githubusercontent.com/u/964655?v=4" width="50;" alt="Flayan"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/ianpatt" title="Ian Patterson">
      <img src="https://avatars.githubusercontent.com/u/292795?v=4" width="50;" alt="Ian Patterson"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/Meridiano" title="Meridiano">
      <img src="https://avatars.githubusercontent.com/u/25160065?v=4" width="50;" alt="Meridiano"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/Bobbyclue" title="Bobbyclue">
      <img src="https://avatars.githubusercontent.com/u/97621924?v=4" width="50;" alt="Bobbyclue"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/epinter" title="Emerson Pinter">
      <img src="https://avatars.githubusercontent.com/u/1561280?v=4" width="50;" alt="Emerson Pinter"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/gazzamc" title="Gary McGovern">
      <img src="https://avatars.githubusercontent.com/u/7975925?v=4" width="50;" alt="Gary McGovern"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/Zzyxz" title="Zzyxz">
      <img src="https://avatars.githubusercontent.com/u/33715692?v=4" width="50;" alt="Zzyxz"/>
    </a>
  </td>
  <td align="center">
    <a href="https://github.com/lStewieAl" title="lStewieAl">
      <img src="https://avatars.githubusercontent.com/u/16544747?v=4" width="50;" alt="lStewieAl"/>
    </a>
  </td>
</tr></table><!--CONTRIBUTORS_END-->

## Credits

This work is based on [CommonLibSSE][CLibSSE] created by [Ryan-rsm-McKenzie](https://github.com/Ryan-rsm-McKenzie) under an [MIT License][CommonLib_MIT]. Without him putting that together, much of the joint Bethesda RE scene would be drastically different. The MIT License is kept for historical purposes only and the [GPL](#License) governs this work. To the extent that you want the [MIT licensed code][CommonLib_MIT], please reference [CommonLibSSE and its forks][CLibSSE].

[CommonLib_MIT]: /CommonLibSF/LICENSES/COMMONLIB
[LICENSE]: COPYING
[CLibSSE]: https://github.com/Ryan-rsm-McKenzie/CommonLibSSE
