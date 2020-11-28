//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_INDEX_OF_IF_HPP_INCLUDED
#define FCPPT_METAL_INDEX_OF_IF_HPP_INCLUDED

#include <fcppt/metal/detail/index_of_if.hpp>

namespace fcppt
{
namespace metal
{
/**
\brief Returns the index of an element of a metal::list that matches a predicate.

\ingroup fcpptmetal

Similar to <code>metal::find_if</code> but asserts that the element is actually in the list.

\tparam List Must be a metal::list.
*/
template <typename List, typename Pred>
using index_of_if = typename fcppt::metal::detail::index_of_if<List, Pred>::type;

}
}

#endif
