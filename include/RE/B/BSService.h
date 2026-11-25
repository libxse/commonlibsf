#pragma once

#include "RE/B/BSLock.h"

namespace RE
{
	namespace BSService
	{
		class QueuedDelegate
		{
		public:
			virtual ~QueuedDelegate() = default;  // 00

			virtual void RunAndDispose()  // 01
			{
				Run();
				delete this;
			}

			virtual void  Unk02() {}                                // 02
			virtual void  Unk03() {}                                // 03
			virtual void* GetProfilerContext() { return nullptr; }  // 04
			virtual void  Unk05() {}                                // 05
			virtual void  Unk06() {}                                // 06
			virtual void  Unk07() {}                                // 07

			virtual void Run() = 0;

			std::uint32_t IncRef() const
			{
				REX::TAtomicRef myRefCount{ refCount };
				return ++myRefCount;
			}

			void Release() const
			{
				REX::TAtomicRef myRefCount{ refCount };
				if (--myRefCount == 0) {
					const_cast<QueuedDelegate*>(this)->RunAndDispose();
				}
			}

			// members
			mutable volatile std::uint32_t refCount{ 1 };       // 08
			std::uint32_t                  pad0C{ 0 };          // 0C
			std::byte                      pad10[0x18]{};       // 10
			BSReadWriteLock                lock;                // 28
			const void*                    profilerCategory{};  // 30
			std::byte                      pad38[0xE8]{};       // 38
		};
		static_assert(offsetof(QueuedDelegate, refCount) == 0x08);
		static_assert(offsetof(QueuedDelegate, lock) == 0x28);
		static_assert(offsetof(QueuedDelegate, profilerCategory) == 0x30);
		static_assert(sizeof(QueuedDelegate) == 0x120);

		namespace detail
		{
			template <class Fn>
			class QueuedFunctorDelegate :
				public QueuedDelegate
			{
			public:
				explicit QueuedFunctorDelegate(Fn a_fn) :
					_fn(std::move(a_fn))
				{}

				void Run() override { _fn(); }

			private:
				Fn _fn;
			};
		}

		class TaskQueue
		{
		public:
			[[nodiscard]] static TaskQueue* GetSingleton()
			{
				static REL::Relocation<TaskQueue**> singleton{ ID::BSService::TaskQueue::Singleton };
				return *singleton;
			}

			void QueueTask(QueuedDelegate*& a_task)
			{
				using func_t = void (*)(TaskQueue*, QueuedDelegate**);
				static REL::Relocation<func_t> func{ ID::BSService::TaskQueue::QueueTask };
				func(this, std::addressof(a_task));
			}

			void AddTask(QueuedDelegate* a_task)
			{
				if (!a_task) {
					return;
				}
				QueueTask(a_task);
				if (a_task) {
					a_task->Release();
				}
			}

			template <class Fn>
				requires(std::invocable<std::remove_cvref_t<Fn>&>)
			void AddTask(Fn&& a_fn)
			{
				AddTask(new detail::QueuedFunctorDelegate<std::remove_cvref_t<Fn>>(std::forward<Fn>(a_fn)));
			}
		};
	}
}
