//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/cast/apply.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>
#include <fcppt/math/detail/init.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{
template <typename T, typename Conv, typename U>
inline T structure_cast(U const &_other)
{
  FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(typename T::storage_type);

  static_assert(
      std::is_same<typename T::dim_wrapper, typename U::dim_wrapper>::value,
      "structure_cast works only on types with the same dimensions");

  return fcppt::math::detail::init<T>([&_other](typename T::size_type const _index) {
    return fcppt::cast::apply<Conv, fcppt::type_traits::value_type<T>>(_other.storage()[_index]);
  });
}

}
}
}

#endif
