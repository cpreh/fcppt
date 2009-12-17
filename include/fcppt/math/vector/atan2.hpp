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


#ifndef FCPPT_MATH_VECTOR_ATAN2_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ATAN2_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/is_null.hpp>
#include <fcppt/math/detail/has_size.hpp>
#include <fcppt/optional_impl.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/mpl/and.hpp>
#include <cmath>

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
inline typename boost::enable_if<
	boost::mpl::and_<
		boost::is_floating_point<
			T
		>,
		math::detail::has_size<
			N,
			2
		>
	>,
	optional<T>
>::type
atan2(
	basic<T, N, S> const &v)
{
	return is_null(v)
		? optional<T>()
		: std::atan2(v.y(), v.x());
}

}
}
}

#endif
