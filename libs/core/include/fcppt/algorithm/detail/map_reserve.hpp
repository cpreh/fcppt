//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_DETAIL_MAP_RESERVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_MAP_RESERVE_HPP_INCLUDED

#include <fcppt/algorithm/detail/optimize_map_v.hpp>
#include <fcppt/algorithm/detail/source_size.hpp>

namespace fcppt::algorithm::detail
{
template <typename Dest, typename Source>
inline void map_reserve(Dest &_dest, Source const &_src)
  requires fcppt::algorithm::detail::optimize_map_v<Dest, Source>
{
  _dest.reserve(
      // some ranges have signed sizes
      static_cast<Dest::size_type>(
          fcppt::algorithm::detail::source_size<Source>::get(_src)));
}

template <typename Dest, typename Source>
inline void map_reserve(Dest &, Source const &)
  requires (!fcppt::algorithm::detail::optimize_map_v<Dest, Source>)
{
}
}

#endif
