//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/detail/structure_cast_fun.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T,
	typename U
>
typename boost::enable_if<
	std::is_same<
		T,
		U
	>,
	T
>::type const
structure_cast(
	U const &u
)
{
	return u;
}

template<
	typename T,
	typename U
>
typename boost::disable_if<
	std::is_same<
		T,
		U
	>,
	T
>::type const
structure_cast(
	U const &u
)
{
	typedef fcppt::math::detail::structure_cast_fun<
		typename T::value_type
	> op_type;

	op_type const op = {};

	static_assert(
		std::is_same<
			typename T::dim_wrapper,
			typename U::dim_wrapper
		>::value,
		"structure_cast works only on types with the same dimensions"
	);

	return T(
		boost::make_transform_iterator(
			u.begin(),
			op
		),
		boost::make_transform_iterator(
			u.end(),
			op
		)
	);
}

}
}
}

#endif
