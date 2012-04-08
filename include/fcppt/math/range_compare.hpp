//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_RANGE_COMPARE_HPP_INCLUDED
#define FCPPT_MATH_RANGE_COMPARE_HPP_INCLUDED

#include <fcppt/math/diff.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
/**
\brief Compares two ranges using an epsilon
\ingroup fcpptmath
\tparam Range A forward-iterable range
\tparam T A numeric type. Can be non-floating-point.

This function returns true if all components of \p r1 are equal to the
corresponding components in \p r2 up to the given epsilon.
*/
template<typename Range,typename T>
typename
boost::enable_if
<
	boost::is_floating_point<typename Range::value_type>,
	bool
>::type
range_compare(
	Range const &r1,
	Range const &r2,
	T const &epsilon)
{
	for(
		typename Range::const_iterator
			i1 =
				r1.begin(),
			i2 =
				r2.begin();
		i1 != r1.end();
		++i1,++i2)
		if (fcppt::math::diff(*i1,*i2) > epsilon)
			return false;

	return true;
}
}
}

#endif
