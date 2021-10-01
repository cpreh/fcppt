//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_NARROW_CAST_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_NARROW_CAST_HPP_INCLUDED

#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/init.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::detail
{
template <typename T, typename U>
inline T narrow_cast(U const &_other)
{
  static_assert(
      std::is_same_v<fcppt::type_traits::value_type<T>, fcppt::type_traits::value_type<U>>,
      "narrow_cast can only be used on the same value_types");

  static_assert(
      T::dim_wrapper::value < U::dim_wrapper::value,
      "narrow_cast can only cast to types with lesser dimensions");

  return fcppt::math::detail::init<T>(
      [&_other]<fcppt::math::size_type Index>(fcppt::math::size_constant<Index>)
      { return fcppt::math::detail::checked_access<Index>(_other); });
}

}

#endif
