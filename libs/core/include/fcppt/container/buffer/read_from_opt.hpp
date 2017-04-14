//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BUFFER_READ_FROM_OPT_HPP_INCLUDED
#define FCPPT_CONTAINER_BUFFER_READ_FROM_OPT_HPP_INCLUDED

#include <fcppt/container/buffer/object_impl.hpp>
#include <fcppt/optional/map.hpp>
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

\tparam Function A function callable as <code>fcppt::optional::object<size_type> (pointer, size_type)</code>.
*/
template<
	typename ValueType,
	typename Function
>
fcppt::optional::object<
	fcppt::container::buffer::object<
		ValueType
	>
>
read_from_opt(
	typename
	fcppt::container::buffer::object<
		ValueType
	>::size_type const _size,
	Function const &_function
)
{
	typedef
	fcppt::container::buffer::object<
		ValueType
	>
	result_type;

	result_type result{
		_size
	};

	return
		fcppt::optional::map(
			_function(
				result.write_data(),
				_size
			),
			[
				&result
			](
				typename
				result_type::size_type const _new_size
			)
			{
				result.written(
					_new_size
				);

				return
					std::move(
						result
					);
			}
		);
}

}
}
}

#endif
