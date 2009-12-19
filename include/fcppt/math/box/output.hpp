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


#ifndef FCPPT_MATH_BOX_OUTPUT_HPP_INCLUDED
#define FCPPT_MATH_BOX_OUTPUT_HPP_INCLUDED

#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/size_type.hpp>
#include <ostream>

namespace fcppt
{
namespace math
{
namespace box
{

template<
	typename T,
	size_type N,
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<Ch, Traits> &stream_,
	basic<T, N> const &box_
)
{
	return stream_
		<< stream_.widen('(')
		<< box_.pos()
		<< stream_.widen(',')
		<< box_.dimension()
		<< stream_.widen(')');
}

}
}
}

#endif
