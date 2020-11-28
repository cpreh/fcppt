//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_INDEX_OF_HPP_INCLUDED
#define FCPPT_METAL_INDEX_OF_HPP_INCLUDED

#include <fcppt/metal/detail/index_of.hpp>

namespace fcppt
{
namespace metal
{
/**
\brief Returns the index of an element of a metal::list.

\ingroup fcpptmetal

Similar to <code>metal::find</code> but asserts that the element is actually in the list.

\tparam List Must be a metal::list.
*/
template <typename List, typename Type>
using index_of = typename fcppt::metal::detail::index_of<List, Type>::type;

}
}

#endif
