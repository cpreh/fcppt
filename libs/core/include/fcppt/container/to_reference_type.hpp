//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_TO_REFERENCE_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_TO_REFERENCE_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
/**
\brief Gets the reference type of a container.

\ingroup fcpptcontainer

If \a Container is <code>const</code>, the result is
<code>Container::const_reference</code>. Otherwise, it is
<code>Container::reference</code>.

\tparam Container A range type.
*/
template <typename Container>
using to_reference_type = std::conditional_t<
    std::is_const_v<Container>,
    typename Container::const_reference,
    typename Container::reference>;

}
}

#endif
