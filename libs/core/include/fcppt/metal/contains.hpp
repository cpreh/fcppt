//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_CONTAINS_HPP_INCLUDED
#define FCPPT_METAL_CONTAINS_HPP_INCLUDED

#include <fcppt/type_traits/to_bool.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace metal
{
/**
\brief Like <code>metal::contains</code>, but returning a boolean.

\ingroup fcpptmetal
*/
template <typename List, typename Value>
using contains = fcppt::type_traits::to_bool<::metal::contains<List, Value>>;

}
}

#endif
