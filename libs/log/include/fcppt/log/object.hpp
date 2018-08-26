//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_OBJECT_HPP_INCLUDED
#define FCPPT_LOG_OBJECT_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/reference_decl.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/level_stream_array_fwd.hpp>
#include <fcppt/log/level_stream_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/optional_level_fwd.hpp>
#include <fcppt/log/parameters_fwd.hpp>
#include <fcppt/log/detail/context_tree_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/log/format/optional_function.hpp>


namespace fcppt
{
namespace log
{

/**
\brief The main log class

\ingroup fcpptlog

Logging is done through objects of this class. In the constructor, it gets a
log context and a log location, providing it with a log level and level
streams.
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
	<code>enabled(level)</code> is false, nothing will be
	logged. An output can be constructed from \link fcppt::log::_ \endlink.

	\param level The log level to log to

	\param output The output to log

	\note You are advised not to use this element function directly,
	because creating an output even if the log object will discard it can
	be significant overhead. Instead, use the macros \link
	FCPPT_LOG_DEBUG\endlink and so on directly.
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	void
	log(
		fcppt::log::level level,
		fcppt::log::detail::temporary_output const &output
	);

	/**
	\brief The level stream corresponding to a log level

	\param level The log level to get the level stream for
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::level_stream const &
	level_sink(
		fcppt::log::level level
	) const;

	/**
	\brief Returns if a level is activated

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
	\brief Returns the current log level
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::optional_level
	level() const;
private:
	typedef
	fcppt::reference<
		fcppt::log::detail::context_tree const
	>
	context_tree_ref;

	object(
		fcppt::log::context &,
		context_tree_ref,
		fcppt::log::parameters const &
	);

	fcppt::log::context &context_;

	context_tree_ref const node_;

	fcppt::log::format::optional_function const formatter_;
};

}
}

#endif
