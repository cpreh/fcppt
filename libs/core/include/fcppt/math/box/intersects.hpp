//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_BOX_INTERSECTS_HPP_INCLUDED
#define FCPPT_MATH_BOX_INTERSECTS_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/vector/at.hpp>

namespace fcppt::math::box
{
/**
\brief Tests if two boxes intersect

\ingroup fcpptmathbox
*/
template <typename T, fcppt::math::size_type N>
inline bool
intersects(fcppt::math::box::object<T, N> const &_a, fcppt::math::box::object<T, N> const &_b)
{
  return fcppt::algorithm::all_of(
      fcppt::math::int_range_count<N>{},
      [&_a, &_b]<fcppt::math::size_type Index>(fcppt::tag<fcppt::math::size_constant<Index>>)
      {
        return fcppt::math::vector::at<Index>(_b.pos()) <
                   fcppt::math::vector::at<Index>(_a.max()) &&
               fcppt::math::vector::at<Index>(_a.pos()) <
                   fcppt::math::vector::at<Index>(_b.max());
      });
}

}

#endif
