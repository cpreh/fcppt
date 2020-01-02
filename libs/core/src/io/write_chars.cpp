//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/io/write_chars.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <ios>
#include <ostream>
#include <fcppt/config/external_end.hpp>


bool
fcppt::io::write_chars(
	std::ostream &_stream,
	char const *const _data,
	std::size_t const _count
)
{
	_stream.write(
		_data,
		fcppt::cast::size<
			std::streamsize
		>(
			fcppt::cast::to_signed(
				_count
			)
		)
	);

	return
		_stream.good();
}
