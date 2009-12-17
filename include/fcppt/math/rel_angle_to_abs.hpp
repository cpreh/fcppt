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


#ifndef FCPPT_MATH_REL_ANGLE_TO_ABS_HPP_INCLUDED
#define FCPPT_MATH_REL_ANGLE_TO_ABS_HPP_INCLUDED

#include <fcppt/math/is_rel_angle.hpp>
#include <fcppt/math/almost_zero.hpp>
#include <fcppt/math/twopi.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/format.hpp>
#include <fcppt/text.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>

namespace fcppt
{
namespace math
{

template<
	typename T
>
typename boost::enable_if<
	boost::is_floating_point<
		T
	>,
	T
>::type
rel_angle_to_abs(
	T const a)
{
	if(!is_rel_angle(a))
		throw exception(
			(format(FCPPT_TEXT("math::rel_angle_to_abs: relative angle %1% out of range!"))
			% a).str()
		);

	if (almost_zero(a))
		return static_cast<T>(0);

	return a > static_cast<T>(0) ? a : twopi<T>()+a;
}

}
}

#endif
