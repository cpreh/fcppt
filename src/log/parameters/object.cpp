//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/ostream.hpp>
#include <fcppt/log/context_location.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/enabled_levels.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/detail/optional_context_location.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/parameters/object.hpp>


fcppt::log::parameters::object::object()
:
	enabled_(
		false
	),
	level_streams_(),
	enabled_levels_(),
	formatter_(),
	context_location_()
{
}

fcppt::log::parameters::object &
fcppt::log::parameters::object::context_location(
	fcppt::log::context_location const &_context_location
)
{
	context_location_ = _context_location;

	return *this;
}

fcppt::log::parameters::object &
fcppt::log::parameters::object::enabled(
	bool const _enabled
)
{
	enabled_ = _enabled;

	return *this;
}

fcppt::log::parameters::object &
fcppt::log::parameters::object::level_streams(
	fcppt::log::level_stream_array const &_level_streams
)
{
	level_streams_ = _level_streams;

	return *this;
}

fcppt::log::parameters::object &
fcppt::log::parameters::object::level_stream(
	fcppt::log::level const _level,
	fcppt::log::level_stream const &_stream
)
{
	level_streams_[
		_level
	]
		= _stream;

	return *this;
}

fcppt::log::parameters::object &
fcppt::log::parameters::object::enabled_levels(
	fcppt::log::enabled_level_array const &_enabled_levels
)
{
	enabled_levels_ = _enabled_levels;

	return *this;
}

fcppt::log::parameters::object &
fcppt::log::parameters::object::activate(
	fcppt::log::level const _level
)
{
	enabled_levels_[
		_level
	] =
		true;

	return *this;
}

fcppt::log::parameters::object &
fcppt::log::parameters::object::formatter(
	fcppt::log::format::function const &_formatter
)
{
	formatter_ = _formatter;

	return *this;
}

fcppt::log::parameters::object &
fcppt::log::parameters::object::level_defaults(
	fcppt::io::ostream &_sink,
	fcppt::log::level const _level
)
{
	this->enabled_levels(
		fcppt::log::enabled_levels(
			_level
		)
	);

	this->level_streams(
		fcppt::log::default_level_streams(
			_sink
		)
	);

	return *this;
}

fcppt::log::detail::optional_context_location const &
fcppt::log::parameters::object::context_location() const
{
	return context_location_;
}

bool
fcppt::log::parameters::object::enabled() const
{
	return enabled_;
}

fcppt::log::level_stream_array const &
fcppt::log::parameters::object::level_streams() const
{
	return level_streams_;
}

fcppt::log::enabled_level_array const &
fcppt::log::parameters::object::enabled_levels() const
{
	return enabled_levels_;
}

fcppt::log::format::function const &
fcppt::log::parameters::object::formatter() const
{
	return formatter_;
}
