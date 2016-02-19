//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/io/buffer.hpp>
#include <fcppt/io/optional_buffer.hpp>
#include <fcppt/io/read_chars.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <istream>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::io::optional_buffer
fcppt::io::read_chars(
	std::istream &_stream,
	std::size_t const _count
)
{
	fcppt::io::buffer result(
		_count
	);

	return
		_stream.read(
			result.data(),
			fcppt::cast::size<
				std::streamsize
			>(
				fcppt::cast::to_signed(
					_count
				)
			)
		)
		?
			fcppt::io::optional_buffer{
				std::move(
					result
				)
			}
		:
			fcppt::io::optional_buffer{}
		;
}
