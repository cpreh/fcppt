//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_FLIP_MAP_HPP_INCLUDED
#define FCPPT_METAL_FLIP_MAP_HPP_INCLUDED

#include <fcppt/metal/detail/flip_map.hpp>

namespace fcppt
{
namespace metal
{
/**
\brief Flips a metal map.

\ingroup fcpptmetal

For each element of \a Map, swaps the key and the value type.
For this to work, the mapped types of the map must all be different ypes.

\tparam Map A metal::map.
*/
template <typename Map>
using flip_map = typename fcppt::metal::detail::flip_map<Map>::type;

}
}

#endif
