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


#ifndef FCPPT_MATH_DETAIL_PI_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_PI_HPP_INCLUDED

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
struct pi;

template<>
struct pi<
	long double
>
{
	static long double get()
	{
		return 3.1415926535897932384626433832795028841971693993751058L;
	}
};

template<>
struct pi<
	double
>
{
	static double get()
	{
		return 3.1415926535897932384626433832795028841971693993751058;
	}
};

template<>
struct pi<
	float
>
{
	static float get()
	{
		// TODO: add another constant for this!
		return static_cast<float>(
			pi<double>::get()
		);
	}
};

}
}
}

#endif
