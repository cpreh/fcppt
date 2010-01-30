//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_OBJECT_HPP_INCLUDED
#define FCPPT_LOG_OBJECT_HPP_INCLUDED

#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/detail/auto_context.hpp>
#include <fcppt/log/parameters/all_fwd.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/temporary_output_fwd.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream_fwd.hpp>
#include <fcppt/log/context_location_fwd.hpp>
#include <fcppt/log/format/object_ptr.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace fcppt
{
namespace log
{

/// The main logger class. If you need a new logger, you should create an object of it.
class object {
	FCPPT_NONCOPYABLE(object)
public:
	//! Constructs a logger. 
	/** See parameters::root and parameters::inherited. */
	FCPPT_SYMBOL explicit object(
		parameters::all const &
	);

	FCPPT_SYMBOL ~object();

	FCPPT_SYMBOL void
	log(
		level::type,
		temporary_output const &
	);

	FCPPT_SYMBOL level_stream &
	level_sink(
		level::type
	);

	FCPPT_SYMBOL level_stream const &
	level_sink(
		level::type
	) const;

	FCPPT_SYMBOL void
	activate(
		level::type
	);

	FCPPT_SYMBOL void
	deactivate(
		level::type
	);

	FCPPT_SYMBOL bool
	activated(
		level::type
	) const;

	FCPPT_SYMBOL void
	enable(
		bool
	);

	FCPPT_SYMBOL bool
	enabled() const;

	FCPPT_SYMBOL io::ostream &
	sink() const;

	FCPPT_SYMBOL format::const_object_ptr const
	formatter() const;

	FCPPT_SYMBOL
	log::context_location const
	context_location() const;

	FCPPT_SYMBOL
	level_stream_array const &
	level_streams() const;

	FCPPT_SYMBOL
	enabled_level_array const &
	enabled_levels() const;
private:
	object const *const parent_;

	io::ostream &sink_;

	detail::auto_context auto_context_;

	format::const_object_ptr const formatter_;

	bool enabled_;

	level_stream_array level_streams_;

	enabled_level_array enabled_levels_;
};

}
}

#endif
