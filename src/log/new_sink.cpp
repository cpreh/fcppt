//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/foreach_enumerator.hpp>
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
	FCPPT_FOREACH_ENUMERATOR(
		cur_level,
		fcppt::log::level
	)
		_logger.level_sink(
			cur_level
		).sink(
			_stream
		);
}
