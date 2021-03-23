//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_BUFFER_APPEND_FROM_HPP_INCLUDED
#define FCPPT_CONTAINER_BUFFER_APPEND_FROM_HPP_INCLUDED

#include <fcppt/container/buffer/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace buffer
{
/**
\brief Appends to a buffer using a function.

\ingroup fcpptcontainerbuffer

Allocates a write area for \a _buffer of size \a _size and then calls
<code>_function(_buffer.write_data(),_size)</code>. The result of the function
is used to expand <code>_buffer</code>'s read area size.

\tparam Function A function callable as <code>size_type (pointer, size_type)</code>.
*/
template <typename T, typename A, typename Function>
fcppt::container::buffer::object<T, A> append_from(
    fcppt::container::buffer::object<T, A> &&_buffer,
    typename fcppt::container::buffer::object<T, A>::size_type const _size,
    Function const &_function)
{
  _buffer.resize_write_area(_size);

  _buffer.written(_function(_buffer.write_data(), _size));

  return std::move(_buffer);
}

}
}
}

#endif
