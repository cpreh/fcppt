//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_BUFFER_APPEND_FROM_OPT_HPP_INCLUDED
#define FCPPT_CONTAINER_BUFFER_APPEND_FROM_OPT_HPP_INCLUDED

#include <fcppt/container/buffer/object_impl.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
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
\brief Appends to a buffer using a function which may fail.

\ingroup fcpptcontainerbuffer

Allocates a buffer <code>buf</code> of size \a _size and then calls
<code>_function(buf.write_data(),_size)</code>. If the result of the function
is nothing, then nothing is returned. Otherwise, The result of the function is
used to set <code>buf</code>'s read area size.

\tparam Function A function callable as <code>fcppt::optional::object<size_type> (pointer,
size_type)</code>.
*/
template <typename T, typename A, typename Function>
fcppt::optional::object<fcppt::container::buffer::object<T, A>> append_from_opt(
    fcppt::container::buffer::object<T, A> &&_buffer,
    typename fcppt::container::buffer::object<T, A>::size_type const _size,
    Function const &_function)
{
  _buffer.resize_write_area(_size);

  return fcppt::optional::map(
      _function(_buffer.write_data(), _size),
      [&_buffer](typename fcppt::container::buffer::object<T, A>::size_type const _new_size) {
        _buffer.written(_new_size);

        return std::move(_buffer);
      });
}

}
}
}

#endif
