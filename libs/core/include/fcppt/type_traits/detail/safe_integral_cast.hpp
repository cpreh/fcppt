//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TYPE_TRAITS_DETAIL_SAFE_INTEGRAL_CAST_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_DETAIL_SAFE_INTEGRAL_CAST_HPP_INCLUDED

#include <fcppt/cast/static_cast_fun.hpp>
#include <fcppt/type_traits/integral_cast.hpp>

namespace fcppt::type_traits::detail
{
template <typename Dest, typename Src>
struct safe_integral_cast
{
  using type = fcppt::type_traits::integral_cast<Dest, fcppt::cast::static_cast_fun, Src>;

  static_assert(static_cast<typename Src::value_type>(type::value) == Src::value);
};

}

#endif
