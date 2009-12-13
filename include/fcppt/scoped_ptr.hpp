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


#ifndef SGE_SCOPED_PTR_HPP_INCLUDED
#define SGE_SCOPED_PTR_HPP_INCLUDED

#include <sge/auto_ptr.hpp>
#include <sge/heap_deleter.hpp>
#include <sge/noncopyable.hpp>
#include <algorithm>

namespace sge
{

template<
	typename T,
	template<
		typename
	> class Deleter = heap_deleter
>
class scoped_ptr {
	SGE_NONCOPYABLE(scoped_ptr)
public:
	typedef T *pointer;

	explicit scoped_ptr(
		pointer p = 0)
	:
		ptr(p)
	{}

	explicit scoped_ptr(
		auto_ptr<T> p)
	:
		ptr(p.release())
	{}

	~scoped_ptr()
	{
		Deleter<T>()(ptr);
	}

	void reset(
		T * p = 0)
	{
		scoped_ptr(p).swap(*this);
	}

	T &operator*() const
	{
		return *ptr;
	}

	T *operator->() const
	{
		return ptr;
	}

	T *get() const
	{
		return ptr;
	}

	typedef T * scoped_ptr::*unspecified_bool_type;

	operator unspecified_bool_type() const
	{
		return ptr == 0
			? 0
			: &scoped_ptr::ptr;
	}

	bool operator! () const
	{
		return !ptr;
	}

	void swap(
		scoped_ptr &b)
	{
		std::swap(
			ptr,
			b.ptr);
	}

	void take(
		auto_ptr<T> p)
	{
		reset();
		ptr = p.release();
	}
private:
	pointer ptr;
};

template<
	typename T
>
void swap(
	scoped_ptr<T> &a,
	scoped_ptr<T> &b)
{
	a.swap(b);
}

template<
	typename T
>
T *
get_pointer(
	scoped_ptr<T> const & p)
{
	return p.get();
}

}

#endif
