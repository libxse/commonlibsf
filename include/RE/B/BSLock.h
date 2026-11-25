#pragma once

namespace RE
{
	class BSNonReentrantSpinLock
	{
	public:
		void               Lock();
		[[nodiscard]] bool TryLock();
		void               Unlock();

	private:
		// members
		volatile std::uint32_t m_lock{};  // 0
	};
	static_assert(sizeof(BSNonReentrantSpinLock) == 0x4);

	class BSReadWriteLock
	{
	public:
		void LockRead();
		void LockWrite();
		void UnlockRead();
		void UnlockWrite();

	private:
		// members
		std::uint32_t          m_writerThread{};  // 0
		volatile std::uint32_t m_lock{};          // 4
	};
	static_assert(sizeof(BSReadWriteLock) == 0x8);

	class BSSpinLock
	{
	public:
		void               Lock();
		[[nodiscard]] bool TryLock();
		void               Unlock();

	private:
		static void UnlockImpl(BSSpinLock* a_lock);

	private:
		// members
		std::uint32_t          m_owningThread{};  // 0
		volatile std::uint32_t m_lock{};          // 4
	};
	static_assert(sizeof(BSSpinLock) == 0x8);

	template <class Mutex>
	struct BSAutoLockDefaultPolicy
	{
	public:
		static void Lock(Mutex& a_mutex) { a_mutex.Lock(); }
		static void Unlock(Mutex& a_mutex) { a_mutex.Unlock(); }
	};
	static_assert(std::is_empty_v<BSAutoLockDefaultPolicy<BSSpinLock>>);

	template <class Mutex>
	struct BSAutoLockReadLockPolicy
	{
	public:
		static void Lock(Mutex& a_mutex) { a_mutex.LockRead(); }
		static void Unlock(Mutex& a_mutex) { a_mutex.UnlockRead(); }
	};
	static_assert(std::is_empty_v<BSAutoLockReadLockPolicy<BSReadWriteLock>>);

	template <class Mutex>
	struct BSAutoLockWriteLockPolicy
	{
	public:
		static void Lock(Mutex& a_mutex) { a_mutex.LockWrite(); }
		static void Unlock(Mutex& a_mutex) { a_mutex.UnlockWrite(); }
	};
	static_assert(std::is_empty_v<BSAutoLockWriteLockPolicy<BSReadWriteLock>>);

	template <class Mutex, template <class> class Policy = BSAutoLockDefaultPolicy>
	class BSAutoLock
	{
	public:
		using mutex_type = Mutex;
		using policy_type = Policy<mutex_type>;

		explicit BSAutoLock(mutex_type& a_mutex) :
			m_lock(std::addressof(a_mutex))
		{
			policy_type::Lock(*m_lock);
		}

		explicit BSAutoLock(mutex_type* a_mutex) :
			m_lock(a_mutex)
		{
			if (m_lock)
				policy_type::Lock(*m_lock);
		}

		~BSAutoLock()
		{
			if (m_lock)
				policy_type::Unlock(*m_lock);
		}

	private:
		// members
		mutex_type* m_lock{};  // 00
	};
	static_assert(sizeof(BSAutoLock<void*>) == 0x8);

	template <class Mutex>
	BSAutoLock(Mutex&) -> BSAutoLock<Mutex>;

	template <class Mutex>
	BSAutoLock(Mutex*) -> BSAutoLock<Mutex>;

	using BSAutoReadLock = BSAutoLock<BSReadWriteLock, BSAutoLockReadLockPolicy>;
	static_assert(sizeof(BSAutoReadLock) == 0x8);

	using BSAutoWriteLock = BSAutoLock<BSReadWriteLock, BSAutoLockWriteLockPolicy>;
	static_assert(sizeof(BSAutoWriteLock) == 0x8);

	template <class T, class Mutex>
	class BSGuarded
	{
	public:
		template <class U, template <class> class Policy = BSAutoLockDefaultPolicy>
		class Guard
		{
		public:
			explicit Guard(U& a_data, Mutex& a_mutex) :
				m_guard(a_mutex),
				m_data(a_data)
			{}

			U&       operator*() { return m_data; }
			U&       operator->() { return m_data; }
			const U& operator*() const { return m_data; }
			const U& operator->() const { return m_data; }

		private:
			// members
			BSAutoLock<Mutex, Policy> m_guard{};  // 0 - Lock guard is first here?
			U&                        m_data;     // 8
		};

		auto Lock()
		{
			return Guard<T>(m_data, m_lock);
		}

		auto LockRead() const
			requires std::is_same_v<Mutex, BSReadWriteLock>
		{
			return Guard<const T, BSAutoLockReadLockPolicy>(m_data, m_lock);
		}

		auto LockWrite()
			requires std::is_same_v<Mutex, BSReadWriteLock>
		{
			return Guard<T, BSAutoLockWriteLockPolicy>(m_data, m_lock);
		}

	private:
		// members
		T             m_data{};  // ??
		mutable Mutex m_lock{};  // ??
	};
}
