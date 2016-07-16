//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_OBJECT_HPP_INCLUDED
#define FCPPT_LOG_OBJECT_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/level_stream_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/parameters_fwd.hpp>
#include <fcppt/log/setting_fwd.hpp>
#include <fcppt/log/detail/auto_context.hpp>
#include <fcppt/log/detail/context_tree_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/log/format/optional_function.hpp>


namespace fcppt
{
namespace log
{

/**
\brief The main logger class

\ingroup fcpptlog

This class represents a logger object, encapsulating a level stream for every
log level, a formatter for the logger itself and which log levels are
activated. You should create one logger object for each subsystem you wish to
enable or disable logging for.
*/
class object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	/**
	\brief Constructs a root logger object
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	object(
		fcppt::log::context &,
		fcppt::log::parameters const &
	);

	/**
	\brief Constructs a child logger object
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	object(
		fcppt::log::object &,
		fcppt::log::parameters const &
	);

	/**
	\brief Constructs a log at a specific location
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	object(
		fcppt::log::context &,
		fcppt::log::location const &,
		fcppt::log::parameters const &
	);

	FCPPT_LOG_DETAIL_SYMBOL
	~object();

	/**
	\brief Logs a message

	Logs a message given by \a output to level \a level. If
	<code>enabled_and_activated(level)</code> is false, nothing will be
	logged. An output can be constructed from \link fcppt::log::_ \endlink.

	\param level The log level to log to

	\param output The output to log

	\note You are advised not to use this element function directly,
	because creating an output even if the logger will discard it can be
	significant overhead. Instead, use the macros FCPPT_LOG_DEBUG and so on
	directly.
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	void
	log(
		fcppt::log::level level,
		fcppt::log::detail::temporary_output const &output
	);

	/**
	\brief The level stream corresponding to a log level

	Returns the level stream corresponding to \a level.

	\param level The log level to get the level stream for
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::level_stream &
	level_sink(
		fcppt::log::level level
	);

	/**
	\brief The level stream corresponding to a log level

	Returns the level stream corresponding to \a level.

	\param level The log level to get the level stream for
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::level_stream const &
	level_sink(
		fcppt::log::level level
	) const;

	/**
	\brief Returns if a level is activated

	Returns if \a level is activated.

	\param level The log level to query the activated state for
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	bool
	enabled(
		fcppt::log::level level
	) const;

	/**
	\brief Returns the associated formatter
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::format::optional_function const &
	formatter() const;

	/**
	\brief Returns the associated level streams
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::level_stream_array const &
	level_streams() const;

	/**
	\brief Returns which levels are enabled
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::enabled_level_array const &
	enabled_levels() const;

	/**
	\brief Returns the current setting
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::setting const &
	setting() const;
private:
	object(
		fcppt::log::detail::context_tree &,
		fcppt::log::parameters const &
	);

	fcppt::log::detail::auto_context auto_context_;

	fcppt::log::format::optional_function const formatter_;

	fcppt::log::level_stream_array level_streams_;
};

}
}

#endif
