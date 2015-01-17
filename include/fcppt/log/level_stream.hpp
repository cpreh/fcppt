//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_STREAM_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_STREAM_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/level_stream_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/log/format/function.hpp>


namespace fcppt
{
namespace log
{

/**
\brief The stream for a logger level

\ingroup fcpptlog

Every logger object a level stream for each logging levels. This class dictates
which sink and formatters should be used for a given level. Objects of this
class can be shared between several logger objects.
*/
class level_stream
{
public:
	level_stream();

	/**
	\brief Constructs a level stream with a sink and a formatter

	Constructs a level stream with sink \a stream and formatter \a
	formatter

	\param stream The stream to log to

	\param formatter The formatting to use for this level
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	level_stream(
		fcppt::io::ostream &stream,
		fcppt::log::format::function const &formatter
	);

	/**
	\brief Destroys a level stream
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	~level_stream();

	/**
	\brief Logs to this level stream

	Logs the output represented by \a output, using additional formatting
	provided by \a additional_formatter.
	fcppt::log::detail::temporary_output can be constructed by \link
	fcppt::log::_ \endlink.

	\param output The output to log

	\param additional_formatter Additional formatting to be used. This
	formatter is used first, and is usually provided by the logger object
	itself.
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	void
	log(
		fcppt::log::detail::temporary_output const &output,
		fcppt::log::format::function const &additional_formatter
	);

	/**
	\brief Sets a new sink

	\param stream The stream to use
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	void
	sink(
		fcppt::io::ostream &stream
	);

	/**
	\brief Returns the associated formatter
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::format::function const &
	formatter() const;
private:
	typedef
	fcppt::optional<
		fcppt::io::ostream &
	>
	ostream_reference;

	ostream_reference dest_;

	fcppt::log::format::function formatter_;
};

}
}

#endif
