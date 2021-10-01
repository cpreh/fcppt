//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_MEMBER_OPERATOR_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MEMBER_OPERATOR_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/linear_access.hpp>

namespace fcppt::math::detail
{
template <typename Type1, typename Type2, typename Function>
Type1 &member_operator(Type1 &_left, Type2 const &_right, Function const &_function)
{
  static_assert(Type1::dim_wrapper::value == Type2::dim_wrapper::value);

  fcppt::algorithm::loop(
      fcppt::math::int_range_count<Type1::dim_wrapper::value>{},
      [&_left, &_right, &_function]<fcppt::math::size_type Index>(
          fcppt::tag<fcppt::math::size_constant<Index>>)
      {
        _function(
            fcppt::math::detail::linear_access<Index>(_left.storage()),
            fcppt::math::detail::linear_access<Index>(_right.storage()));
      });

  return _left;
}

}

#endif
