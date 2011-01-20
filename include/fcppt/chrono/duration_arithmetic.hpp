//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_DURATION_ARITHMETIC_HPP_INCLUDED
#define FCPPT_CHRONO_DURATION_ARITHMETIC_HPP_INCLUDED

#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/chrono/common_type.hpp>
#include <fcppt/chrono/is_duration.hpp>
#include <boost/static_assert.hpp>

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
typename common_type<
	duration<
		Rep1,
		Period1
	>,
	duration<
		Rep2,
		Period2
	>
>::type
operator +(
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
		typename common_type<
			duration<
				Rep1,
				Period1
			>,
			duration<
				Rep2,
				Period2
			>
		>::type(
			lhs
		)
		+= rhs;
}

template<
	typename Rep1,
	typename Period1,
	typename Rep2,
	typename Period2
>
typename common_type<
	duration<
		Rep1,
		Period1
	>,
	duration<
		Rep2,
		Period2
	>
>::type
operator -(
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
		typename common_type<
			duration<
				Rep1,
				Period1
			>,
			duration<
				Rep2,
				Period2
			>
		>::type(
			lhs
		)
		-= rhs;
}

template<
	typename Rep1,
	typename Period,
	typename Rep2
>
duration<
	typename common_type<
		Rep1,
		Rep2
	>::type,
	Period
>
operator *(
	duration<
		Rep1,
		Period
	> const &d,
	Rep2 const &s
)
{
	return
		duration<
			typename common_type<
				Rep1,
				Rep2
			>::type,
			Period
		>(
			d
		)
		*= s;
}

template<
	typename Rep1,
	typename Period,
	typename Rep2
>
duration<
	typename common_type<
		Rep1,
		Rep2
	>::type,
	Period
>
operator *(
	Rep1 const &s,
	duration<
		Rep2,
		Period
	> const &d
)
{
	return d * s;
}

template<
	typename Rep1,
	typename Period,
	typename Rep2
>
duration<
	typename common_type<
		Rep1,
		Rep2
	>::type,
	Period
>
operator /(
	duration<
		Rep1,
		Period
	> const &d,
	Rep2 const &s
)
{
	return
		duration<
			typename common_type<
				Rep1,
				Rep2
			>::type,
			Period
		>(
			d
		)
		/= s;
}

template<
	typename Rep1,
	typename Period1,
	typename Rep2,
	typename Period2
>
typename common_type<
	Rep1,
	Rep2
>::type
operator /(
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
	typedef typename common_type<
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
		/
		ct(
			rhs
		).count();
}

template<
	typename Rep1,
	typename Period,
	typename Rep2
>
duration<
	typename common_type<
		Rep1,
		Rep2
	>::type,
	Period
>
operator %(
	duration<
		Rep1,
		Period
	> const &d,
	Rep2 const &s
)
{
	typedef typename common_type<
		Rep1,
		Rep2
	>::type ct;

	BOOST_STATIC_ASSERT(
		!is_duration<
			Rep2
		>::value
	);

	return
		duration<
			ct,
			Period
		>(
			d
		)
		%= s;
}

template<
	typename Rep1,
	typename Period1,
	typename Rep2,
	typename Period2
>
typename common_type<
	duration<
		Rep1,
		Period1
	>,
	duration<
		Rep2,
		Period2
	>
>::type
operator %(
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
		typename common_type<
			duration<
				Rep1,
				Period1
			>,
			duration<
				Rep2,
				Period2
			>
		>::type(
			lhs
		)
		%= rhs;
}

}
}

#endif
