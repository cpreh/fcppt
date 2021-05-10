//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_PUSH_BACK_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_PUSH_BACK_HPP_INCLUDED

#include <fcppt/array/init.hpp>
#include <fcppt/array/push_back.hpp>
#include <fcppt/math/from_array.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/static_storage_impl.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{
template <typename Dest, typename Src>
inline Dest push_back(Src const &_src, fcppt::type_traits::value_type<Src> const &_value)
{
  static_assert(Dest::static_size::value == Src::static_size::value + 1U);

  FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(typename Dest::storage_type);

  using src_storage = fcppt::math::detail::
      static_storage<fcppt::type_traits::value_type<Src>, Src::static_size::value>;

  return fcppt::math::from_array<Dest>(fcppt::array::push_back(
      fcppt::array::init<typename src_storage::array_type>(
          [&_src]<std::size_t Index>(std::integral_constant<std::size_t,Index>)
          { return fcppt::math::detail::checked_access<Index>(_src); }),
      _value));
}

}
}
}

#endif
