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


#ifndef FCPPT_MATH_VECTOR_DOT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DOT_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>

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
dot(
	basic<T, N, S> const &l,
	basic<T, N, S> const &r)
{
	if(l.size() != r.size())
		throw exception(
			FCPPT_TEXT("Dimensions of vectors do not match in dot()!"));

	T result(static_cast<T>(0));

	for(typename basic<T, N, S>::size_type i = 0; i < l.size(); ++i)
		result += l[i] * r[i];

	return result;
}

}
}
}

#endif
