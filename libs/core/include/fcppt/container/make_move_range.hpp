//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_MAKE_MOVE_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_MAKE_MOVE_RANGE_HPP_INCLUDED

#include <fcppt/container/move_range_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container
{
/**
\brief Creates a move range from a container

\ingroup fcpptcontainer

\param _container Must be an rvalue reference to a container.

\tparam Container A container type.
*/
template <typename Container>
inline fcppt::container::move_range<std::remove_reference_t<Container>>
make_move_range(Container &&_container)
{
  static_assert(
      std::is_rvalue_reference_v<decltype(_container)>, "Container must be an rvalue reference");

  return fcppt::container::move_range<std::remove_reference_t<Container>>(
      std::forward<Container>(_container));
}

}

#endif
