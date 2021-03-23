//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_INTERVAL_HPP_INCLUDED
#define FCPPT_METAL_INTERVAL_HPP_INCLUDED

#include <fcppt/metal/detail/interval.hpp>

namespace fcppt
{
namespace metal
{
/**
\brief Creates a list of std::integral_constants that form an interval.

\ingroup fcpptmetal

Returns <code>metal::list<std::integral_constant<Type,Begin>, ...,
std::integral_constant<Type,End-1>></code>.

\tparam Type Must be an integral type.
*/
template <typename Type, Type Begin, Type End>
using interval = typename fcppt::metal::detail::interval<Type, Begin, End>::type;

}
}

#endif
