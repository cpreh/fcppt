//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_BOX_DETAIL_INIT_HPP_INCLUDED
#define FCPPT_MATH_BOX_DETAIL_INIT_HPP_INCLUDED

#include <fcppt/array/get.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/is_box.hpp>
#include <fcppt/math/detail/init_function.hpp>
#include <fcppt/math/vector/init.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/type_traits/value_type.hpp>

namespace fcppt::math::box::detail
{
template <typename Box, typename InitSecond, typename Function>
Box init(InitSecond const &_init_second, Function const &_function)
{
  static_assert(fcppt::math::box::is_box<Box>::value, "Box must be a box::object");

  using value_type = fcppt::type_traits::value_type<Box>;

  using result_array =
      fcppt::array::object<fcppt::tuple::object<value_type, value_type>, Box::dim_wrapper::value>;

  auto const results(fcppt::array::init<result_array>(
      fcppt::math::detail::init_function<Function>(_function)));

  return Box{
      fcppt::math::vector::init<typename Box::vector>(
          [&results]<fcppt::math::size_type Index>(fcppt::math::size_constant<Index>)
          { return fcppt::tuple::get<0>(fcppt::array::get<Index>(results)); }),
      _init_second([&results]<fcppt::math::size_type Index>(fcppt::math::size_constant<Index>)
                   { return fcppt::tuple::get<1>(fcppt::array::get<Index>(results)); })};
}

}

#endif
