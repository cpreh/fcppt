//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_DETAIL_MAP_RESERVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_MAP_RESERVE_HPP_INCLUDED

#include <fcppt/algorithm/detail/optimize_map_v.hpp>
#include <fcppt/algorithm/detail/source_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm::detail
{
template <typename Dest, typename Source>
inline std::enable_if_t<fcppt::algorithm::detail::optimize_map_v<Dest, Source>, void>
map_reserve(Dest &_dest, Source const &_src)
{
  _dest.reserve(
      // some ranges have signed sizes
      static_cast<typename Dest::size_type>(
          fcppt::algorithm::detail::source_size<Source>::get(_src)));
}

template <typename Dest, typename Source>
inline std::enable_if_t<!fcppt::algorithm::detail::optimize_map_v<Dest, Source>, void>
map_reserve(Dest &, Source const &)
{
}

}

#endif
