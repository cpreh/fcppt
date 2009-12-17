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


#ifndef FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T,
	typename N,
	typename M,
	typename S1,
	typename S2
>
fcppt::math::vector::basic<T, M, S2>
operator *(
	basic<T, N, M, S1> const &m,
	vector::basic<T, N, S2> const &v)
{
	typedef vector::basic<T, M, S2> result_type;
	result_type ret(
		result_type::null());

	for(typename result_type::size_type i = 0; i < v.size(); ++i)
		for(typename basic<T, N, M, S2>::size_type j = 0; j < N::value; ++j)
			ret[i] += v[j] * m[j][i];
	return ret;
}

}
}
}

#endif
