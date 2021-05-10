//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DIM_IS_QUADRATIC_HPP_INCLUDED
#define FCPPT_MATH_DIM_IS_QUADRATIC_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/algorithm/loop_break_metal.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/dim/at.hpp>
#include <fcppt/math/dim/object_impl.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{
/**
\brief Checks if all elements of the dim are the same

\ingroup fcpptmathdim

\param _dim The dimension to check
*/
template <typename T, fcppt::math::size_type N, typename S>
bool is_quadratic(fcppt::math::dim::object<T, N, S> const &_dim)
{
  return fcppt::algorithm::all_of(
      fcppt::math::int_range_count<N>{},
      [&_dim, _first = fcppt::math::dim::at<0>(_dim)]<fcppt::math::size_type Index>(
          fcppt::tag<fcppt::math::size_constant<Index>>)
      { return fcppt::math::dim::at<Index>(_dim) == _first; });
}

}
}
}

#endif
