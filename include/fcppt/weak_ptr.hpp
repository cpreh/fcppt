/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_WEAK_PTR_HPP_INCLUDED
#define SGE_WEAK_PTR_HPP_INCLUDED

#include <sge/weak_ptr_fwd.hpp>
#include <sge/shared_ptr_fwd.hpp>
#include <boost/weak_ptr.hpp>

namespace sge
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
