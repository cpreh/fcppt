//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/detail/structure_cast_fun.hpp>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>

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
T const
structure_cast(
	U const &u
)
{
	typedef structure_cast_fun<
		typename T::value_type
	> op_type;

	op_type const op = {};

	BOOST_STATIC_ASSERT((
		boost::is_same<
			typename T::dim_wrapper,
			typename U::dim_wrapper
		>::value
	));

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
