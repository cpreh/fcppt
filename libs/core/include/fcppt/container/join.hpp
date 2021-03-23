//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_JOIN_HPP_INCLUDED
#define FCPPT_CONTAINER_JOIN_HPP_INCLUDED

#include <fcppt/container/detail/join_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
/**
\brief Joins two containers.

\ingroup fcpptcontainer

Joins containers \a _first and all containers from \a _args, by inserting the
containers from \a _args into \a _first.

\param _first The left container.

\param _args The other containers, which will be inserted into the left
container.

\tparam Container A container class that supports insert of iterator ranges.
*/
template <typename Container, typename... Args>
inline fcppt::type_traits::remove_cv_ref_t<Container> join(Container &&_first, Args &&..._args)
{
  return fcppt::container::detail::join_impl(
      std::forward<Container>(_first), std::forward<Args>(_args)...);
}

}
}

#endif
