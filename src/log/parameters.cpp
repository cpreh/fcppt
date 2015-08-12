//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/ostream.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/context_location.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/enabled_levels.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/detail/optional_context_location.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/format/optional_function.hpp>


fcppt::log::parameters::parameters(
	fcppt::log::enabled_level_array const &_enabled_levels,
	fcppt::log::level_stream_array const &_level_streams
)
:
	enabled_{
		false
	},
	level_streams_(
		_level_streams
	),
	enabled_levels_(
		_enabled_levels
	),
	formatter_(),
	context_location_()
{
}

fcppt::log::parameters::parameters(
	fcppt::io::ostream &_sink,
	fcppt::log::level const _level
)
:
	fcppt::log::parameters(
		fcppt::log::enabled_levels(
			_level
		),
		fcppt::log::default_level_streams(
			_sink
		)
	)
{
}

fcppt::log::parameters &
fcppt::log::parameters::context_location(
	fcppt::log::context_location const &_context_location
)
{
	context_location_ =
		fcppt::log::detail::optional_context_location(
			_context_location
		);

	return
		*this;
}

fcppt::log::parameters &
fcppt::log::parameters::context_location(
	fcppt::log::context &_context,
	fcppt::log::location const &_location
)
{
	return
		this->context_location(
			fcppt::log::context_location(
				_context,
				_location
			)
		);
}

fcppt::log::parameters &
fcppt::log::parameters::enabled(
	bool const _enabled
)
{
	enabled_ =
		_enabled;

	return
		*this;
}

fcppt::log::parameters &
fcppt::log::parameters::level_stream(
	fcppt::log::level const _level,
	fcppt::log::level_stream const &_stream
)
{
	level_streams_[
		_level
	]
		= _stream;

	return
		*this;
}

fcppt::log::parameters &
fcppt::log::parameters::activate(
	fcppt::log::level const _level
)
{
	enabled_levels_[
		_level
	] =
		true;

	return
		*this;
}

fcppt::log::parameters &
fcppt::log::parameters::formatter(
	fcppt::log::format::function const &_formatter
)
{
	formatter_ =
		fcppt::log::format::optional_function(
			_formatter
		);

	return
		*this;
}

fcppt::log::detail::optional_context_location const &
fcppt::log::parameters::context_location() const
{
	return
		context_location_;
}

bool
fcppt::log::parameters::enabled() const
{
	return
		enabled_;
}

fcppt::log::level_stream_array const &
fcppt::log::parameters::level_streams() const
{
	return
		level_streams_;
}

fcppt::log::enabled_level_array const &
fcppt::log::parameters::enabled_levels() const
{
	return
		enabled_levels_;
}

fcppt::log::format::optional_function const &
fcppt::log::parameters::formatter() const
{
	return
		formatter_;
}
