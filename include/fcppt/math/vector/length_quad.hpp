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


#ifndef FCPPT_MATH_VECTOR_LENGTH_QUAD_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_LENGTH_QUAD_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <boost/spirit/home/phoenix/operator/arithmetic.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <numeric>

namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename T,
	typename N,
	typename S
>
typename basic<T, N, S>::value_type
length_quad(
	basic<T, N, S> const &v)
{
	using boost::phoenix::arg_names::arg1;
	using boost::phoenix::arg_names::arg2;

	return std::accumulate(
		v.begin(),
		v.end(),
		static_cast<T>(0),
		arg1 + arg2 * arg2);
}

}
}
}

#endif
