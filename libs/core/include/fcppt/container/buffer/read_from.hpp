//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BUFFER_READ_FROM_HPP_INCLUDED
#define FCPPT_CONTAINER_BUFFER_READ_FROM_HPP_INCLUDED

#include <fcppt/container/buffer/append_from.hpp>


namespace fcppt
{
namespace container
{
namespace buffer
{

/**
\brief Reads into a buffer using a function.

\ingroup fcpptcontainerbuffer

Allocates a buffer <code>buf</code> of size \a _size and then calls
<code>_function(buf.write_data(),_size)</code>. The result of the function
is used to set <code>buf</code>'s read area size.

\tparam Buffer An \link fcppt::container::buffer::object\endlink.

\tparam Function A function callable as <code>size_type (pointer, size_type)</code>.
*/
template<
	typename Buffer,
	typename Function
>
inline
Buffer
read_from(
	typename
	Buffer::size_type const _size,
	Function const &_function
)
{
	return
		fcppt::container::buffer::append_from(
			Buffer{
				0u
			},
			_size,
			_function
		);
}

}
}
}

#endif
