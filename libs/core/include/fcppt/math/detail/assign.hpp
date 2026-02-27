//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_ASSIGN_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ASSIGN_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp> // IWYU pragma: keep
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/size_constant.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/storage_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::detail
{
template <typename Dest, typename Src>
inline void assign(Dest &_dest, Src const &_src)
{
  static_assert(std::is_same_v<
                fcppt::math::detail::storage_size<typename Dest::storage_type>,
                fcppt::math::detail::storage_size<typename Src::storage_type>>);

  fcppt::algorithm::loop(
      fcppt::math::int_range_count<
          fcppt::math::detail::storage_size<typename Src::storage_type>::value>{},
      [&_dest, &_src]<fcppt::math::size_type Index>(fcppt::tag<fcppt::math::size_constant<Index>>) {
        // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-avoid-unchecked-container-access)
        _dest.storage()[Index] = _src.storage()[Index];
      });
}

}

#endif
