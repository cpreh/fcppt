//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_AT_OPTIONAL_HPP_INCLUDED
#define FCPPT_CONTAINER_AT_OPTIONAL_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/to_value_type.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace fcppt::container
{
/**
\brief Returns an element as an optional at a given position.

\ingroup fcpptcontainer

If \a _index is in the range of \a _container, the element at \a _index is
returned. Otherwise, the result is the empty optional.

\tparam Container Must be a random-access container.
*/
template <typename Container>
fcppt::optional::reference<fcppt::container::to_value_type<Container>>
at_optional(Container &_container, typename Container::size_type const _index)
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

  return fcppt::optional::make_if(_index < _container.size(), [&_container, _index] {
    return fcppt::make_ref(*(_container.begin() + fcppt::cast::to_signed(_index)));
  });

FCPPT_PP_POP_WARNING
}
}

#endif
