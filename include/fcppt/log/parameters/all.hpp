//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_PARAMETERS_ALL_HPP_INCLUDED
#define FCPPT_LOG_PARAMETERS_ALL_HPP_INCLUDED

#include <fcppt/log/parameters/all_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/context_location.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/format/const_object_ptr.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{
namespace parameters
{

/// The parameters class that can be used to specify all arguments
class all
{
public:
	/// Constructs the parameters class providing a sink
	FCPPT_SYMBOL explicit all(
		io::ostream &
	);

	/// Specifies the parent logger
	FCPPT_SYMBOL all
	parent(
		object const &
	);

	/// Set the logger's context and location
	FCPPT_SYMBOL all
	context_location(
		log::context *,
		log::location const &
	);

	/// Sets the logger's enabled status
	FCPPT_SYMBOL all
	enabled(
		bool
	);

	/// Sets the logger's level streams
	FCPPT_SYMBOL all
	level_streams(
		level_stream_array const &
	);

	/// Sets the logger's enabled arrays
	FCPPT_SYMBOL all
	enabled_levels(
		enabled_level_array const &
	);

	/// Sets the logger's formatter
	FCPPT_SYMBOL all
	formatter(
		format::const_object_ptr
	);

	FCPPT_SYMBOL io::ostream &
	sink() const;

	FCPPT_SYMBOL object const *
	parent() const;

	FCPPT_SYMBOL log::context_location const &
	context_location() const;

	FCPPT_SYMBOL bool
	enabled() const;

	FCPPT_SYMBOL level_stream_array const &
	level_streams() const;

	FCPPT_SYMBOL enabled_level_array const &
	enabled_levels() const;

	FCPPT_SYMBOL format::const_object_ptr const
	formatter() const;
private:
	io::ostream *sink_;

	object const *parent_;

	bool enabled_;

	level_stream_array level_streams_;

	enabled_level_array enabled_levels_;

	format::const_object_ptr formatter_;

	log::context_location context_location_;
};

}
}
}

#endif
