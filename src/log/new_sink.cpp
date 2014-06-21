//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_enum_range.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/new_sink.hpp>
#include <fcppt/log/object.hpp>


void
fcppt::log::new_sink(
	fcppt::log::object &_logger,
	fcppt::io::ostream &_stream
)
{
	for(
		fcppt::log::level level
		:
		fcppt::make_enum_range<
			fcppt::log::level
		>()
	)
		_logger.level_sink(
			level
		).sink(
			_stream
		);
}
