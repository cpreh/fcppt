//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_BOX_CONTAINS_POINT_HPP_INCLUDED
#define FCPPT_MATH_BOX_CONTAINS_POINT_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/math/vector/object_impl.hpp>

namespace fcppt::math::box
{
/**
\brief Test if a box contains a point

\ingroup fcpptmathbox
*/
template <typename T, typename S, fcppt::math::size_type N>
inline bool contains_point(
    fcppt::math::box::object<T, N> const &_box, fcppt::math::vector::object<T, N, S> const &_point)
{
  return fcppt::algorithm::all_of(
      fcppt::math::int_range_count<N>{},
      [&_box, &_point]<fcppt::math::size_type Index>(fcppt::tag<fcppt::math::size_constant<Index>>)
      {
        return fcppt::math::vector::at<Index>(_point) >=
                   fcppt::math::vector::at<Index>(_box.pos()) &&
               fcppt::math::vector::at<Index>(_point) < fcppt::math::vector::at<Index>(_box.max());
      });
}

}

#endif
