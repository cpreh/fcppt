//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_INTERVAL_DISTANCE_HPP_INCLUDED
#define FCPPT_MATH_INTERVAL_DISTANCE_HPP_INCLUDED

#include <fcppt/homogenous_pair_impl.hpp>
#include <fcppt/literal.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Calculates the distance of two intervals

\ingroup fcpptmath

Returns the distance of the intervals \a _i1 and \a _i2.

\tparam Type Must support <code>< </code> and <code>-</code>
*/
template<
	typename Type
>
Type
interval_distance(
	fcppt::homogenous_pair<
		Type
	> const _i1,
	fcppt::homogenous_pair<
		Type
	> const _i2
)
{
	return
		_i1.second < _i2.first
		?
			_i2.first - _i1.second
		:
			_i2.second < _i1.first
		?
			_i1.first - _i2.second
		:
			fcppt::literal<
				Type
			>(
				0
			)
		;
}

}
}

#endif
