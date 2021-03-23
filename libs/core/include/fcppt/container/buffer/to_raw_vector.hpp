//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_BUFFER_TO_RAW_VECTOR_HPP_INCLUDED
#define FCPPT_CONTAINER_BUFFER_TO_RAW_VECTOR_HPP_INCLUDED

#include <fcppt/container/buffer/object_impl.hpp>
#include <fcppt/container/raw_vector/object_impl.hpp>

namespace fcppt
{
namespace container
{
namespace buffer
{
/**
\brief Convert a buffer into a raw_vector.

\ingroup fcpptcontainerbuffer
*/
template <typename T, typename A>
fcppt::container::raw_vector::object<T, A>
to_raw_vector(fcppt::container::buffer::object<T, A> &&_buffer) noexcept
{
  return fcppt::container::raw_vector::object<T, A>{_buffer.release()};
}

}
}
}

#endif
