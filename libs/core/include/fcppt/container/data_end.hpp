//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_DATA_END_HPP_INCLUDED
#define FCPPT_CONTAINER_DATA_END_HPP_INCLUDED

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/data.hpp>
#include <fcppt/container/to_pointer_type.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace fcppt::container
{
/**
\brief Returns a pointer one past the end of a random-access container>

\ingroup fcpptcontainer

Returns a pointer to one past the end of \a _container, or the null pointer if
\a _container is empty.

\tparam Container Must be a random-access container.
*/
template <typename Container>
fcppt::container::to_pointer_type<Container> data_end(Container &_container)
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE
  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
  return fcppt::container::data(_container) + fcppt::cast::to_signed(_container.size());
FCPPT_PP_POP_WARNING
}

}

#endif
