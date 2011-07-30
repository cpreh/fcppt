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
typename chrono::common_type<
	chrono::duration<
		Rep1,
		Period1
	>,
	chrono::duration<
		Rep2,
		Period2
	>
>::type
operator +(
	chrono::duration<
		Rep1,
		Period1
	> const &_lhs,
	chrono::duration<
		Rep2,
		Period2
	> const &_rhs
)
{
	return
		typename chrono::common_type<
			chrono::duration<
				Rep1,
				Period1
			>,
			chrono::duration<
				Rep2,
				Period2
			>
		>::type(
			_lhs
		)
		+= _rhs;
}

template<
	typename Rep1,
	typename Period1,
	typename Rep2,
	typename Period2
>
typename chrono::common_type<
	chrono::duration<
		Rep1,
		Period1
	>,
	chrono::duration<
		Rep2,
		Period2
	>
>::type
operator -(
	chrono::duration<
		Rep1,
		Period1
	> const &_lhs,
	chrono::duration<
		Rep2,
		Period2
	> const &_rhs
)
{
	return
		typename chrono::common_type<
			chrono::duration<
				Rep1,
				Period1
			>,
			chrono::duration<
				Rep2,
				Period2
			>
		>::type(
			_lhs
		)
		-= _rhs;
}

template<
	typename Rep1,
	typename Period,
	typename Rep2
>
chrono::duration<
	typename chrono::common_type<
		Rep1,
		Rep2
	>::type,
	Period
>
operator *(
	chrono::duration<
		Rep1,
		Period
	> const &_duration,
	Rep2 const &_scalar
)
{
	return
		chrono::duration<
			typename chrono::common_type<
				Rep1,
				Rep2
			>::type,
			Period
		>(
			_duration
		)
		*= _scalar;
}

template<
	typename Rep1,
	typename Period,
	typename Rep2
>
chrono::duration<
	typename chrono::common_type<
		Rep1,
		Rep2
	>::type,
	Period
>
operator *(
	Rep1 const &_scalar,
	chrono::duration<
		Rep2,
		Period
	> const &_duration
)
{
	return
		_duration * _scalar;
}

template<
	typename Rep1,
	typename Period,
	typename Rep2
>
chrono::duration<
	typename chrono::common_type<
		Rep1,
		Rep2
	>::type,
	Period
>
operator /(
	chrono::duration<
		Rep1,
		Period
	> const &_duration,
	Rep2 const &_scalar
)
{
	BOOST_STATIC_ASSERT(
		sizeof(Rep1) == 0
	);

	return
		chrono::duration<
			typename chrono::common_type<
				Rep1,
				Rep2
			>::type,
			Period
		>(
			_duration
		)
		/= _scalar;
}

template<
	typename Rep1,
	typename Period1,
	typename Rep2,
	typename Period2
>
typename chrono::common_type<
	Rep1,
	Rep2
>::type
operator /(
	chrono::duration<
		Rep1,
		Period1
	> const &_lhs,
	chrono::duration<
		Rep2,
		Period2
	> const &_rhs
)
{
	typedef typename chrono::common_type<
		chrono::duration<
			Rep1,
			Period1
		>,
		chrono::duration<
			Rep2,
			Period2
		>
	>::type ct;

	return
		ct(
			_lhs
		).count()
		/
		ct(
			_rhs
		).count();
}

template<
	typename Rep1,
	typename Period,
	typename Rep2
>
chrono::duration<
	typename chrono::common_type<
		Rep1,
		Rep2
	>::type,
	Period
>
operator %(
	chrono::duration<
		Rep1,
		Period
	> const &_duration,
	Rep2 const &_scalar
)
{
	typedef typename chrono::common_type<
		Rep1,
		Rep2
	>::type ct;

	BOOST_STATIC_ASSERT(
		!chrono::is_duration<
			Rep2
		>::value
	);

	return
		chrono::duration<
			ct,
			Period
		>(
			_duration	
		)
		%= _scalar;
}

template<
	typename Rep1,
	typename Period1,
	typename Rep2,
	typename Period2
>
typename common_type<
	chrono::duration<
		Rep1,
		Period1
	>,
	chrono::duration<
		Rep2,
		Period2
	>
>::type
operator %(
	chrono::duration<
		Rep1,
		Period1
	> const &_lhs,
	chrono::duration<
		Rep2,
		Period2
	> const &_rhs
)
{
	return
		typename chrono::common_type<
			chrono::duration<
				Rep1,
				Period1
			>,
			chrono::duration<
				Rep2,
				Period2
			>
		>::type(
			_lhs
		)
		%= _rhs;
}

}
}

#endif
