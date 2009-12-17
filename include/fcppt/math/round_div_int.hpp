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


#ifndef FCPPT_MATH_ROUND_DIV_INT_HPP_INCLUDED
#define FCPPT_MATH_ROUND_DIV_INT_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_integral.hpp>

namespace fcppt
{
namespace math
{
template<typename T>
typename boost::enable_if<boost::is_integral<T>, T>::type round_div_int(const T  l, const T r)
{
	return (r % 2)
		? ((l * 2 / r) + 1) / 2 // for odd numbers up to half the types capacity
		: (l + (r / 2)) / r;    // for even numbers at least up to half till up
		                        // to 100% of the types capacity, depending on r
		                        // greater r -> less max l
}
}
}

#endif
