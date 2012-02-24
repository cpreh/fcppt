//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DEFAULT_LEVEL_STREAMS_HPP_INCLUDED
#define FCPPT_LOG_DEFAULT_LEVEL_STREAMS_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/level_stream_array.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Constructs the default level streams

Each level stream will log to \a stream and get a corresponding \link
fcppt::log::format::default_level \endlink as its formatter.

\return A stream array consisting of a default stream for each level
*/
FCPPT_SYMBOL
fcppt::log::level_stream_array const
default_level_streams(
	fcppt::io::ostream &stream
);

}
}

#endif
