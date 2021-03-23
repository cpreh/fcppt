//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_DETAIL_GET_UNSAFE_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_GET_UNSAFE_IMPL_HPP_INCLUDED

#include <fcppt/variant/detail/has_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <variant>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{
template <typename Variant, typename U, typename StdVariant>
std::conditional_t<std::is_const_v<StdVariant>, U const &, U &>
get_unsafe_impl(StdVariant &_variant)
{
  static_assert(
      fcppt::variant::detail::has_type<std::remove_const_t<Variant>, U>::value,
      "Invalid variant type");

  return *std::get_if<U>(&_variant);
}

}
}
}

#endif
