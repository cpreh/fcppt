//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/format/default_level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/container/array_impl.hpp>
#include <fcppt/foreach_enumerator.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/tr1/functional.hpp>

fcppt::log::level_stream_array const
fcppt::log::default_level_streams(
	io::ostream &_sink
)
{
	level_stream_array ret;

	FCPPT_FOREACH_ENUMERATOR(
		i,
		level
	)
	{
		ret[i] =
			make_shared_ptr<
				level_stream
			>(
				std::tr1::ref(
					_sink
				),
				format::default_level(
					i
				)
			);
	}

	return ret;
}
