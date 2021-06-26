//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DIM_CONTENTS_HPP_INCLUDED
#define FCPPT_MATH_DIM_CONTENTS_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/storage_size.hpp>
#include <fcppt/math/dim/object_impl.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{
/**
\brief Returns the area/volume of the dimension

\ingroup fcpptmathdim

This is equal to the product of all components of the dimension.
*/
template <typename T, fcppt::math::size_type N, typename S>
T contents(fcppt::math::dim::object<T, N, S> const &_dim)
{
  return fcppt::algorithm::fold(
      fcppt::math::int_range_count<fcppt::math::detail::storage_size<S>::value>{},
      fcppt::literal<T>(1),
      [&_dim]<fcppt::math::size_type Index>(
          fcppt::tag<fcppt::math::size_constant<Index>>, T const &_value)
      { return _value * fcppt::math::detail::linear_access<Index>(_dim.storage()); });
}

}
}
}

#endif
