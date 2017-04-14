//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BUFFER_RESIZE_WRITE_AREA_HPP_INCLUDED
#define FCPPT_CONTAINER_BUFFER_RESIZE_WRITE_AREA_HPP_INCLUDED

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/buffer/object_impl.hpp>
#include <fcppt/container/buffer/read_from.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace buffer
{

/**
\brief Resizes the write area.

\ingroup fcpptcontainerbuffer

The read area of \a buffer is copied into the result if it fits, and is
truncated otherwise.
*/
template<
	typename T,
	typename A
>
fcppt::container::buffer::object<
	T,
	A
>
resize_write_area(
	fcppt::container::buffer::object<
		T,
		A
	> const &_buffer,
	typename
	fcppt::container::buffer::object<
		T,
		A
	>::size_type const _new_size
)
{
	// TODO: Optimize this with reserve-like functionality.
	typedef
	fcppt::container::buffer::object<
		T,
		A
	>
	buffer_type;

	return
		fcppt::container::buffer::read_from<
			T
		>(
			_new_size
			+
			_buffer.read_size(),
			[
				&_buffer
			](
				typename
				buffer_type::pointer const _data,
				typename
				buffer_type::size_type
			)
			{
				std::uninitialized_copy(
					_buffer.read_data(),
					_buffer.read_data_end(),
					_data
				);

				return
					_buffer.read_size();
			}
		);
}

}
}
}

#endif
