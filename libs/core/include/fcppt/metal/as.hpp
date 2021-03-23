//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_AS_HPP_INCLUDED
#define FCPPT_METAL_AS_HPP_INCLUDED

#include <fcppt/metal/detail/as.hpp>

namespace fcppt
{
namespace metal
{
/**
\brief Turns a metal list into another type.

\ingroup fcpptmetal

For <code>List=metal::list<t_1,...,t_n></code>
the result type is <code>Type<t_1,...,t_n></code>.

\tparam List Must be a metal::list.
*/
template <template <typename...> class Type, typename List>
using as = typename fcppt::metal::detail::as<Type, List>::type;

}
}

#endif
