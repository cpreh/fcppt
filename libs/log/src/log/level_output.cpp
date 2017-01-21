//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/ostream.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_output.hpp>
#include <fcppt/log/level_to_string.hpp>


fcppt::io::ostream &
fcppt::log::operator<<(
	fcppt::io::ostream &_stream,
	fcppt::log::level const _level
)
{
	return
		_stream
		<<
		fcppt::log::level_to_string(
			_level
		);
}
