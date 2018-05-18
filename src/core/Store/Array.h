//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

/* toy */
#include <obj/Vector.h>
#include <core/Generated/Forward.h>
#include <core/Store/Store.h>
#include <core/Store/StoreObserver.h>

/* std */
#include <vector>
#include <algorithm>

using namespace mud; namespace toy
{
	template <class T>
	class _refl_ Array : public StoreBase<Array<T>, T>
	{
	public:
		typedef T R;

	public:
		Array() : m_store() {}
		~Array() { this->clear(); }

		inline T& deref(T* const& ref) const { return *ref; }

		inline const std::vector<T*>& store() const { return m_store; }
		inline std::vector<T*>& store() { return m_store; }


		void safeAdd(T& object)
		{
			if(!has(object))
				add(object);
		}

		//void push(Object* object);
		void add(T& object)
		{
			m_store.push_back(&object);
			this->notifyAdd(object);
		}

		void add(T* object)
		{
			add(*object);
		}

		void insert(T& object, size_t index)
		{
			m_store.insert(m_store.begin() + index, &object);
			this->notifyAdd(object);
		}

		void insert(T* object, size_t index)
		{
			insert(*object, index);
		}

		void remove(size_t pos)
		{
			T& object = *m_store[pos];
			this->notifyRemove(object);
			m_store.erase(m_store.begin() + pos);
		}

		void remove(T& object)
		{
			this->notifyRemove(object);
			vector_remove(m_store, &object);
		}

		void move(size_t from, size_t to)
		{
			T& object = *m_store[from];
			m_store.erase(m_store.begin() + from);
			m_store.insert(m_store.begin() + to, &object);
		}

		T& pop()
		{
			//if(empty())
			//	return 0;

			T& object = *m_store.back();
			remove(m_store.size());

			return object;
		}

		T& pop_front()
		{
			//if(empty())
			//	return 0;

			T& object = *m_store.front();
			remove(size_t(0));

			return object;
		}

		bool has(T& object) const
		{
			return std::find(m_store.begin(), m_store.end(), &object) != m_store.end();
		}

		T& at(size_t pos) { return *m_store[pos]; }
		size_t index(T& object) { for(size_t i = 0; i < m_store.size(); ++i) if(m_store[i] == &object) return i; return size_t(-1); }

		bool empty() const { return m_store.empty(); }

	protected:
		std::vector<T*> m_store;
	};

	template <class T_Array>
	class Chained : public T_Array, public StoreObserver<typename T_Array::T>
	{
	public:
		typedef typename T_Array::T T;

	public:
		Chained() : T_Array() {}

		void handleAdd(T& object) { this->add(object); }
		void handleRemove(T& object) { this->remove(object); }
	};
}
