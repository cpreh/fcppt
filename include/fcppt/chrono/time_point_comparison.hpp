//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_TIME_POINT_COMPARISON_HPP_INCLUDED
#define FCPPT_CHRONO_TIME_POINT_COMPARISON_HPP_INCLUDED

#include <fcppt/chrono/time_point_impl.hpp>

namespace fcppt
{
namespace chrono
{

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
bool
operator ==(
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
		== rhs.time_since_epoch();
}

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
bool
operator !=(
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
		!(lhs == rhs);
}

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
bool
operator <(
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
		< rhs.time_since_epoch();
}

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
bool
operator <=(
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
		!(rhs < lhs);
}

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
bool
operator >(
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
		rhs < lhs;
}

template<
	typename Clock,
	typename Duration1,
	typename Duration2
>
bool
operator >=(
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
		!(lhs < rhs);
}

}
}

#endif
