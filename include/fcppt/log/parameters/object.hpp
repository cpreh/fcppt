//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_PARAMETERS_OBJECT_HPP_INCLUDED
#define FCPPT_LOG_PARAMETERS_OBJECT_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/context_location.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/optional_context_location.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/parameters/object_fwd.hpp>


namespace fcppt
{
namespace log
{
namespace parameters
{

/// The parameters class that can be used to specify all arguments
class object
{
	FCPPT_NONASSIGNABLE(
		object
	);
public:
	/// Constructs the parameters class providing a sink
	FCPPT_SYMBOL
	explicit
	object(
		fcppt::io::ostream &
	);

	/// Specifies the context and location
	FCPPT_SYMBOL
	fcppt::log::parameters::object &
	context_location(
		fcppt::log::context_location const &
	);

	/// Sets the logger's enabled status
	FCPPT_SYMBOL
	fcppt::log::parameters::object &
	enabled(
		bool
	);

	/// Sets the logger's level streams
	FCPPT_SYMBOL
	fcppt::log::parameters::object &
	level_streams(
		fcppt::log::level_stream_array const &
	);

	/// Sets the logger's enabled arrays
	FCPPT_SYMBOL
	fcppt::log::parameters::object &
	enabled_levels(
		fcppt::log::enabled_level_array const &
	);

	/// Sets the logger's formatter
	FCPPT_SYMBOL
	fcppt::log::parameters::object &
	formatter(
		fcppt::log::format::function const &
	);

	FCPPT_SYMBOL
	fcppt::log::parameters::object &
	level_defaults(
		fcppt::log::level::type
	);

	FCPPT_SYMBOL
	fcppt::io::ostream &
	sink() const;

	FCPPT_SYMBOL
	fcppt::log::optional_context_location const &
	context_location() const;

	FCPPT_SYMBOL
	bool
	enabled() const;

	FCPPT_SYMBOL
	fcppt::log::level_stream_array const &
	level_streams() const;

	FCPPT_SYMBOL
	fcppt::log::enabled_level_array const &
	enabled_levels() const;

	FCPPT_SYMBOL
	fcppt::log::format::function const &
	formatter() const;
private:
	fcppt::io::ostream &sink_;

	bool enabled_;

	fcppt::log::level_stream_array level_streams_;

	fcppt::log::enabled_level_array enabled_levels_;

	fcppt::log::format::function formatter_;

	fcppt::log::optional_context_location context_location_;
};

}
}
}

#endif
