//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/foreach_enumerator.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/container/array_impl.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/format/default_level.hpp>


fcppt::log::level_stream_array const
fcppt::log::default_level_streams(
	fcppt::io::ostream &_sink
)
{
	fcppt::log::level_stream_array ret;

	FCPPT_FOREACH_ENUMERATOR(
		index,
		fcppt::log::level
	)
	{
		ret[
			static_cast<
				fcppt::log::level_stream_array::size_type
			>(
				index
			)
		] =
			fcppt::make_shared_ptr<
				fcppt::log::level_stream
			>(
				_sink,
				fcppt::log::format::default_level(
					index
				)
			);
	}

	return ret;
}
