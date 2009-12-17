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


#ifndef FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

#define FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION(op)\
template<\
	typename T,\
	typename N,\
	typename M,\
	typename S\
>\
basic<T, N, M, S> const \
operator op(\
	basic<T, N, M, S> const &a,\
	basic<T, N, M, S> const &b)\
{\
	return basic<T, N, M, S>(a) op##= b;\
}

FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION(+)
FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION(-)

#undef FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION

template<
	typename T,
	typename N,
	typename M1,
	typename M2,
	typename S
>
basic<T, N, N, S> const
operator *(
	basic<T, M1, N, S> const &a,
	basic<T, N, M2, S> const &b)
{
	typedef basic<T, M1, M2, S> result_type;
	result_type ret;
	for(typename basic<T, M1, N, S>::size_type i = 0; i < M1::value; ++i)
		for(typename basic<T, N, M2, S>::size_type j = 0; j < M2::value; ++j)
		{
			typename result_type::value_type v(0);
			for(typename result_type::size_type r = 0; r < N::value; ++r)
				v += a[i][r] * b[r][j];
			ret[i][j] = v;
		}
	return ret;

}

}
}
}

#endif
