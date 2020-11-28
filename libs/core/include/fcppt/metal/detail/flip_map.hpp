//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_DETAIL_FLIP_MAP_HPP_INCLUDED
#define FCPPT_METAL_DETAIL_FLIP_MAP_HPP_INCLUDED

#include <fcppt/metal/flip_pair.hpp>
#include <fcppt/metal/is_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace metal
{
namespace detail
{
template <typename Map>
struct flip_map
{
  using type = ::metal::transform<::metal::lambda<fcppt::metal::flip_pair>, Map>;

  static_assert(
      fcppt::metal::is_set<::metal::keys<type>>::value,
      "flip_map can only be used on an injective map");
};

}
}
}

#endif
