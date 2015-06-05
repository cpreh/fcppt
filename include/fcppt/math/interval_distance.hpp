//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_INTERVAL_DISTANCE_HPP_INCLUDED
#define FCPPT_MATH_INTERVAL_DISTANCE_HPP_INCLUDED

#include <fcppt/homogenous_pair_impl.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Calculates the distance of two intervals

\ingroup fcpptmath

Returns the distance (as defined below) of the intervals \a _i1 and \a _i2.

Distance can be zero if the intervals touch, or negative if they overlap.
If they only partially overlap, the distance is \em negative the common length where they overlap.
If one completely contains the other, the "outer" interval is split in two parts by the "inner" one.
In this case, the (again negative) length of the \em shorter part is returned. Therefore the distance
is zero if the inner interval touches the outer one.

\tparam Type Must support <code>< </code> and <code>-</code>
*/
template<
	typename Type
>
Type
interval_distance(
	fcppt::homogenous_pair<
		Type
	> _i1,
	fcppt::homogenous_pair<
		Type
	> _i2
)
{
	// handle symmetric cases by swapping
	if (_i1.second <= _i2.second)
		std::swap(_i1,_i2);

	return
	_i2.first <= _i1.first
	?
	// this difference represents
	// either the positive distance between them or if they overlap,
	// the amount by which they do (as negative "distance")
	_i1.first - _i2.second
	:
	// one completely contains the other, so return the smaller of the two parts
	std::max(
		_i2.second - _i1.second,
		_i1.first - _i2.first
	);
}

}
}

#endif
