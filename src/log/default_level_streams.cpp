//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/enum_array_fold.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/format/default_level.hpp>


fcppt::log::level_stream_array
fcppt::log::default_level_streams(
	fcppt::io::ostream &_sink
)
{
	return
		fcppt::algorithm::enum_array_fold<
			fcppt::log::level_stream_array
		>(
			[
				&_sink
			](
				fcppt::log::level const _index
			)
			{
				return
					fcppt::log::level_stream(
						_sink,
						fcppt::log::format::default_level(
							_index
						)
					);
			}
		);
}
