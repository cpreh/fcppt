//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_DURATION_COMPARISON_HPP_INCLUDED
#define FCPPT_CHRONO_DURATION_COMPARISON_HPP_INCLUDED

#include <fcppt/chrono/common_type.hpp>
#include <fcppt/chrono/duration_impl.hpp>


namespace fcppt
{
namespace chrono
{

template<
	typename Rep1,
	typename Period1,
	typename Rep2,
	typename Period2
>
bool
operator ==(
	duration<
		Rep1,
		Period1
	> const &lhs,
	duration<
		Rep2,
		Period2
	> const &rhs
)
{
	typedef typename
		common_type<
			duration<
				Rep1,
				Period1
			>,
			duration<
				Rep2,
				Period2
			>
		>::type ct;

	return
		ct(
			lhs
		).count()
		==
		ct(
			rhs
		).count();
}

template<
	typename Rep1,
	typename Period1,
	typename Rep2,
	typename Period2
>
bool
operator !=(
	duration<
		Rep1,
		Period1
	> const &lhs,
	duration<
		Rep2,
		Period2
	> const &rhs
)
{
	return
		!(lhs == rhs);
}

template<
	typename Rep1,
	typename Period1,
	typename Rep2,
	typename Period2
>
bool
operator <(
	duration<
		Rep1,
		Period1
	> const &lhs,
	duration<
		Rep2,
		Period2
	> const &rhs
)
{
	typedef typename
		common_type<
			duration<
				Rep1,
				Period1
			>,
			duration<
				Rep2,
				Period2
			>
		>::type ct;

	return
		ct(
			lhs
		).count()
		<
		ct(
			rhs
		).count();
}

template<
	typename Rep1,
	typename Period1,
	typename Rep2,
	typename Period2
>
bool
operator <=(
	duration<
		Rep1,
		Period1
	> const &lhs,
	duration<
		Rep2,
		Period2
	> const &rhs
)
{
	return
		!(rhs < lhs);
}

template<
	typename Rep1,
	typename Period1,
	typename Rep2,
	typename Period2
>
bool
operator >(
	duration<
		Rep1,
		Period1
	> const &lhs,
	duration<
		Rep2,
		Period2
	> const &rhs
)
{
	return
		rhs < lhs;
}

template<
	typename Rep1,
	typename Period1,
	typename Rep2,
	typename Period2
>
bool
operator >=(
	duration<
		Rep1,
		Period1
	> const &lhs,
	duration<
		Rep2,
		Period2
	> const &rhs
)
{
	return
		!(lhs < rhs);
}

}
}

#endif
