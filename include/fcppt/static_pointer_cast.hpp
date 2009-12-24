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


#ifndef FCPPT_STATIC_POINTER_CAST_HPP_INCLUDED
#define FCPPT_STATIC_POINTER_CAST_HPP_INCLUDED

#include <fcppt/shared_ptr_impl.hpp>

namespace fcppt
{

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
shared_ptr<T, Deleter> const
static_pointer_cast(
	shared_ptr<U, Deleter> const &r
)
{
	return shared_ptr<T, Deleter>(
		r,
		boost::detail::static_cast_tag()
	);
}

}

#endif
