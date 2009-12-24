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


#ifndef FCPPT_SCOPED_PTR_DECL_HPP_INCLUDED
#define FCPPT_SCOPED_PTR_DECL_HPP_INCLUDED

#include <fcppt/scoped_ptr_fwd.hpp>
#include <fcppt/auto_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/safe_bool.hpp>

namespace fcppt
{

template<
	typename T,
	template<
		typename
	> class Deleter
>
class scoped_ptr
{
	FCPPT_NONCOPYABLE(scoped_ptr)
	FCPPT_SAFE_BOOL(scoped_ptr)
public:
	typedef T &reference;
	typedef T *pointer;

	explicit scoped_ptr(
		pointer = 0
	);

	explicit scoped_ptr(
		auto_ptr<T>
	);

	~scoped_ptr();

	void
	reset(
		pointer = 0
	);

	reference
	operator*() const;

	pointer
	operator->() const;

	pointer
	get() const;

	bool
	operator! () const;

	void
	swap(
		scoped_ptr &
	);

	void
	take(
		auto_ptr<T> p
	);
private:
	bool
	boolean_test() const;

	pointer ptr;
};

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
swap(
	scoped_ptr<T, Deleter> &,
	scoped_ptr<T, Deleter> &
);

}

#endif
