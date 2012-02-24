//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_STREAM_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_STREAM_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/level_stream_fwd.hpp>
#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/log/format/function.hpp>


namespace fcppt
{
namespace log
{

/// The stream for a logger level
/**
 * Every log::object has a level_stream for each of its logging levels.
 * This class dictates which sink and formatters should be used.
*/
class level_stream
{
	FCPPT_NONASSIGNABLE(
		level_stream
	);
public:
	/// Constructs a level_stream with a sink and a formatter
	FCPPT_SYMBOL
	level_stream(
		fcppt::io::ostream &,
		fcppt::log::format::function const &
	);

	FCPPT_SYMBOL
	~level_stream();

	FCPPT_SYMBOL
	void
	log(
		fcppt::log::detail::temporary_output const &,
		fcppt::log::format::function const &addtional_formatter
	);

	FCPPT_SYMBOL
	void
	formatter(
		fcppt::log::format::function const &
	);

	FCPPT_SYMBOL
	fcppt::log::format::function const &
	formatter() const;
private:
	fcppt::io::ostream &dest_;

	fcppt::log::format::function formatter_;
};

}
}

#endif
