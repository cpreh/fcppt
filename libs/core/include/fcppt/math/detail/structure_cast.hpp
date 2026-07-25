//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/cast/apply.hpp>
#include <fcppt/math/is_static_storage.hpp>
#include <fcppt/math/detail/init.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::detail
{
template <typename T, typename Conv, typename U>
inline T structure_cast(U const &_other)
  requires(
      std::is_same_v<typename T::dim_wrapper, typename U::dim_wrapper> &&
      fcppt::math::is_static_storage<typename T::storage_type>::value)
{
  return fcppt::math::detail::init<T>([&_other](T::size_type const _index) {
    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-avoid-unchecked-container-access)
    return fcppt::cast::apply<Conv, fcppt::type_traits::value_type<T>>(_other.storage()[_index]);
  });
}
}

#endif
