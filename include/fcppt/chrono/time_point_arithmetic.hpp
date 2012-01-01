//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_TIME_POINT_ARITHMETIC_HPP_INCLUDED
#define FCPPT_CHRONO_TIME_POINT_ARITHMETIC_HPP_INCLUDED

#include <fcppt/chrono/common_type.hpp>
#include <fcppt/chrono/duration_arithmetic.hpp>
#include <fcppt/chrono/time_point_impl.hpp>


namespace fcppt
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
