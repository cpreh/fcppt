//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_TO_POINTER_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_TO_POINTER_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
/**
\brief Gets the pointer type of a container.

\ingroup fcpptcontainer

If \a Container is <code>const</code>, the result is
<code>Container::const_pointer</code>. Otherwise, it is
<code>Container::pointer</code>.

\tparam Container A range type.
*/
template <typename Container>
using to_pointer_type = std::conditional_t<
    std::is_const_v<Container>,
    typename Container::const_pointer,
    typename Container::pointer>;

}
}

#endif
