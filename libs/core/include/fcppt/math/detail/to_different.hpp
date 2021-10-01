//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_TO_DIFFERENT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_TO_DIFFERENT_HPP_INCLUDED

#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/init.hpp>

namespace fcppt::math::detail
{
template <typename Dest, typename Source>
inline Dest to_different(Source const &_source)
{
  static_assert(Dest::dim_wrapper::value == Source::dim_wrapper::value, "dim_wrappers must match");

  return fcppt::math::detail::init<Dest>(
      [&_source]<fcppt::math::size_type Index>(fcppt::math::size_constant<Index>)
      { return fcppt::math::detail::checked_access<Index>(_source); });
}

}

#endif
