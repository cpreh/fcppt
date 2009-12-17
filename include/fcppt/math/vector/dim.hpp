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


#ifndef FCPPT_MATH_VECTOR_DIM_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DIM_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

#define FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(op)\
template<\
	typename T,\
	typename N,\
	typename S1,\
	typename S2\
>\
basic<T, N, S1> const \
operator op(\
	basic<T, N, S1> a,\
	dim::basic<T, N, S2> const &b)\
{\
	for(typename N::value_type i = 0; i < a.size(); ++i)\
		a[i] op##= b[i];\
	return a;\
}

FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(+)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(-)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(*)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(/)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(%)

#undef FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION

}
}
}

#endif
