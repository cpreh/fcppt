//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_NEW_SINK_HPP_INCLUDED
#define FCPPT_LOG_NEW_SINK_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/object_fwd.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Sets a sink for all level streams of a logger

\ingroup fcpptlog

Sets \a stream as a new sink for every level stream of \a logger
*/
FCPPT_SYMBOL
void
new_sink(
	fcppt::log::object &logger,
	fcppt::io::ostream &stream
);

}
}

#endif
