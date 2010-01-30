//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_WEAK_PTR_HPP_INCLUDED
#define FCPPT_WEAK_PTR_HPP_INCLUDED

#include <fcppt/weak_ptr_fwd.hpp>
#include <fcppt/shared_ptr_fwd.hpp>
#include <boost/weak_ptr.hpp>

namespace fcppt
{

template<
	typename T,
	template<
		typename
	> class Deleter
>
class weak_ptr {
public:
	typedef boost::weak_ptr<T> impl_type;

	typedef T element_type;

	weak_ptr()
	:
		impl()
	{}

	template<
		typename Y
	>
	weak_ptr(
		weak_ptr<Y, Deleter> const &r)
	:
		impl(r.boost_ptr())
	{}

	template<
		typename Y
	>
	weak_ptr(
		shared_ptr<Y, Deleter> const &r)
	:
		impl(r.boost_ptr())
	{}

 	shared_ptr<T, Deleter> const
	lock() const // never throws
	{
        	return shared_ptr<T, Deleter>(
			impl.lock());
	}

	long use_count() const // never throws
	{
		return impl.use_count();
	}

	bool expired() const // never throws
	{
		return impl.expired();
	}

	void reset()
	{
		impl.reset();
 	}

	void swap(
		weak_ptr &other)
	{
		impl.swap(other.impl);
	}

	impl_type const
	boost_ptr() const
	{
		return impl;
	}
private:
	impl_type impl;
};

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
bool operator<(
	weak_ptr<T, Deleter> const & a,
	weak_ptr<U, Deleter> const & b)
{
	return a.boost_ptr() < b.boost_ptr();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void swap(
	weak_ptr<T, Deleter> &a,
	weak_ptr<T, Deleter> &b)
{
	a.swap(b);
}

}

#endif
