//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_FIND_OPT_ITERATOR_HPP_INCLUDED
#define FCPPT_CONTAINER_FIND_OPT_ITERATOR_HPP_INCLUDED

#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/optional/object_impl.hpp>

namespace fcppt::container
{
/**
\brief Returns an iterator from a find operation or an empty optional.

Searches for \a _key in the associative container \a _container. If \a _key is
found, its iterator is returned. Otherwise, the empty optional is returned.

\ingroup fcpptcontainer

\tparam Container Must be an associative container.

\tparam Key Must be a key that can be searched for.
*/
template <typename Container, typename Key>
fcppt::optional::object<fcppt::container::to_iterator_type<Container>>
find_opt_iterator(Container &_container, Key const &_key)
{
  auto const it(_container.find(_key));

  using result_type = fcppt::optional::object<fcppt::container::to_iterator_type<Container>>;

  return it != _container.end() ? result_type(it) : result_type();
}

}

#endif
