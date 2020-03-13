//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BUFFER_READ_FROM_OPT_HPP_INCLUDED
#define FCPPT_CONTAINER_BUFFER_READ_FROM_OPT_HPP_INCLUDED

#include <fcppt/container/buffer/append_from_opt.hpp>
#include <fcppt/optional/object_impl.hpp>


namespace fcppt
{
namespace container
{
namespace buffer
{

/**
\brief Reads into a buffer using a function which may fail.

\ingroup fcpptcontainerbuffer

Allocates a buffer <code>buf</code> of size \a _size and then calls
<code>_function(buf.write_data(),_size)</code>. If the result of the function
is nothing, then nothing is returned. Otherwise, The result of the function is
used to set <code>buf</code>'s read area size.

\tparam Buffer An #fcppt::container::buffer::object.

\tparam Function A function callable as <code>fcppt::optional::object<size_type> (pointer, size_type)</code>.
*/
template<
	typename Buffer,
	typename Function
>
fcppt::optional::object<
	Buffer
>
read_from_opt(
	typename
	Buffer::size_type const _size,
	Function const &_function
)
{
	return
		fcppt::container::buffer::append_from_opt(
			Buffer{
				0U
			},
			_size,
			_function
		);
}

}
}
}

#endif
