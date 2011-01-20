//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_STREAM_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_STREAM_HPP_INCLUDED

#include <fcppt/log/level_stream_fwd.hpp>
#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/log/format/const_object_ptr.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/nonassignable.hpp>

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
	FCPPT_NONASSIGNABLE(level_stream)
public:
	/// Constructs a level_stream with a sink and a formatter
	FCPPT_SYMBOL level_stream(
		io::ostream &,
		format::const_object_ptr
	);

	FCPPT_SYMBOL ~level_stream();

	FCPPT_SYMBOL void
	log(
		detail::temporary_output const &,
		format::const_object_ptr addtional_formatter
	);

	FCPPT_SYMBOL void
	formatter(
		format::const_object_ptr
	);

	FCPPT_SYMBOL format::const_object_ptr const
	formatter() const;
private:
	io::ostream &dest_;
	format::const_object_ptr formatter_;
};

}
}

#endif
