//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_RANGE_COMPARE_HPP_INCLUDED
#define FCPPT_MATH_RANGE_COMPARE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
/// Since the machine epsilon most often is _not_ the correct way to
/// handle floating point comparisons, this function takes two ranges
/// (two types having <code>::%const_iterator</code> as well as begin/end to be
/// exact) and compares them pointwise. Can be applied to dim/vector
/// and other types.
template<typename Range1,typename Range2,typename T>
bool
range_compare(
	Range1 const &r1,
	Range2 const &r2,
	T const &epsilon)
{
	typename Range1::const_iterator i1 = r1.begin();
	typename Range2::const_iterator i2 = r2.begin();

	for(; i1 != r1.end(); ++i1,++i2)
		if (std::abs(*i1 - *i2) > epsilon) // FIXME: use math::diff!
			return false;

	return true;
}
}
}

#endif
