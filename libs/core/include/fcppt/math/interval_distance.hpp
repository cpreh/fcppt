//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_INTERVAL_DISTANCE_HPP_INCLUDED
#define FCPPT_MATH_INTERVAL_DISTANCE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/object_impl.hpp>
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
In this case, the (again negative) length of the \em shorter part is returned. Therefore the
distance is zero if the inner interval touches the outer one.

\tparam Type Must support <code>< </code> and <code>-</code>
*/
template <typename Type>
Type interval_distance(fcppt::tuple::object<Type, Type> _i1, fcppt::tuple::object<Type, Type> _i2)
{
  Type const &i1_first{fcppt::tuple::get<0>(_i1)};
  Type const &i1_second{fcppt::tuple::get<1>(_i1)};
  Type const &i2_first{fcppt::tuple::get<0>(_i2)};
  Type const &i2_second{fcppt::tuple::get<1>(_i2)};

  // handle symmetric cases by swapping
  if (i1_second <= i2_second)
  {
    std::swap(_i1, _i2);
  }

  return i2_first <= i1_first
             ?
             // this difference represents
             // either the positive distance between them or if they overlap,
             // the amount by which they do (as negative "distance")
             i1_first - i2_second
             :
             // one completely contains the other, so return the smaller of the two parts
             std::max(i2_second - i1_second, i1_first - i2_first);
}
}
}

#endif
