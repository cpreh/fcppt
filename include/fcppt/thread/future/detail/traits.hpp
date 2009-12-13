#ifndef SGE_THREAD_FUTURE_DETAIL_TRAITS_HPP_INCLUDED
#define SGE_THREAD_FUTURE_DETAIL_TRAITS_HPP_INCLUDED

#include <sge/scoped_ptr.hpp>
#include <boost/thread/detail/move.hpp>

namespace sge
{
namespace thread
{
namespace future
{
namespace detail
{
template<typename T>
class traits
{
public:
	typedef scoped_ptr<T> storage;
	typedef T const & source_reference;
	typedef boost::detail::thread_move_t<T> move_source;

	static void init(
		storage &,
		T const &);

	static void init(
		storage &,
		move_source);

	static T move(
		storage &);

	static void move(
		storage &,
		T &);

	static void cleanup(
		storage &);
};

template<typename T>
class traits<T &>
{
public:
	typedef T* storage;
	typedef T& source_reference;
	struct move_source {};

	static void init(
		storage &,
		T &);

	static T &move(
		storage &);

	static void cleanup(
		storage &);
};

/*
template<>
class traits<void>
{
public:
	typedef bool storage;

	inline static void init(
		storage &);

	inline static void move(
		storage &);

	inline static void cleanup(
		storage &);
};
*/
}
}
}
}

template<typename T>
void sge::thread::future::detail::traits<T>::init(
	storage &_storage,
	T const &t)
{
	_storage.reset(
		new T(
			t));
}

template<typename T>
void sge::thread::future::detail::traits<T>::init(
	storage &_storage,
	move_source t)
{
	_storage.reset(
		new T(
			t));
}

template<typename T>
T sge::thread::future::detail::traits<T>::move(
	storage &_storage)
{
	T res(
		*_storage);
	cleanup(
		_storage);
	return res;
}

template<typename T>
void sge::thread::future::detail::traits<T>::move(
	storage &_storage,
	T &_dest)
{
	_dest = *_storage;
	cleanup(_storage);
}

template<typename T>
void sge::thread::future::detail::traits<T>::cleanup(
	storage &_storage)
{
	_storage.reset();
}

template<typename T>
void sge::thread::future::detail::traits<T&>::init(
	storage &_storage,
	T &t)
{
	_storage = &t;
}

template<typename T>
T &sge::thread::future::detail::traits<T&>::move(
	storage &_storage)
{
	T &res = *_storage;
	cleanup(
		_storage);
	return res;
}

template<typename T>
void sge::thread::future::detail::traits<T&>::cleanup(
	storage &_storage)
{
	_storage = 0;
}

/*
void sge::thread::future::detail::traits<void>::init(
	storage &_storage)
{
	_storage = true;
}

void sge::thread::future::detail::traits<void>::cleanup(
	storage &_storage)
{
	_storage = false;
}
*/

#endif // SGE_THREAD_FUTURE_DETAIL_TRAITS_HPP_INCLUDED
