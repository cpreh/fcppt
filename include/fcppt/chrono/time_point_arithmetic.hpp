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


#ifndef SGE_CHRONO_TIME_POINT_ARITHMETIC_HPP_INCLUDED
#define SGE_CHRONO_TIME_POINT_ARITHMETIC_HPP_INCLUDED

#include <sge/chrono/time_point_impl.hpp>
#include <sge/chrono/common_type.hpp>

namespace sge
{
namespace chrono
{

template<
	typename Clock,
	typename Duration1,
	typename Rep2,
	typename Period2
>
time_point<
	Clock,
	typename common_type<
		Duration1,
		duration<
			Rep2,
			Period2
		>
	>::type
>
operator +(
	time_point<
		Clock,
		Duration1
	> const &lhs,
	duration<
		Rep2,
		Period2
	> const &rhs
)
{
	return
		time_point<
			Clock,
			typename common_type<
				Duration1,
				duration<
					Rep2,
					Period2
				>
			>::type
		>(
			lhs
		)
		+= rhs;
}

template<
	typename Rep1,
	typename Period1,
	typename Clock,
	typename Duration2
>
time_point<
	Clock,
	typename common_type<
		duration<
			Rep1,
			Period1
		>,
		Duration2
	>::type
>
operator +(
	duration<
		Rep1,
		Period1
	> const &lhs,
	time_point<
		Clock,
		Duration2
	> const &rhs
)
{
	return rhs + lhs;
}

template<
	typename Clock,
	typename Duration1,
	typename Rep2,
	typename Period2
>
time_point<
	Clock,
	typename common_type<
		Duration1,
		duration<
			Rep2,
			Period2
		>
	>::type
>
operator -(
	time_point<
		Clock,
		Duration1
	> const &lhs,
	duration<
		Rep2,
		Period2
	> const &rhs
)
{
	return rhs + (-lhs);
}

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
typename common_type<
	Duration1,
	Duration2
>::type
operator -(
	time_point<
		Clock,
		Duration1
	> const &lhs,
	time_point<
		Clock,
		Duration2
	> const &rhs
)
{
	return
		lhs.time_since_epoch()
		- rhs.time_since_epoch();
}

}
}

#endif
