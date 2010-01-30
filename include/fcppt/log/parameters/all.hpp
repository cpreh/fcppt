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
#include <fcppt/log/format/object_ptr.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{
namespace parameters
{

class all {
public:
	FCPPT_SYMBOL explicit all(
		io::ostream &
	);

	FCPPT_SYMBOL all
	parent(
		object const &
	);

	FCPPT_SYMBOL all
	context_location(
		log::context *,
		log::location const &
	);

	FCPPT_SYMBOL all
	enabled(
		bool
	);

	FCPPT_SYMBOL all
	level_streams(
		level_stream_array const &
	);

	FCPPT_SYMBOL all
	enabled_levels(
		enabled_level_array const &
	);

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
