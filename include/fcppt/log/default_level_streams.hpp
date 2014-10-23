//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DEFAULT_LEVEL_STREAMS_HPP_INCLUDED
#define FCPPT_LOG_DEFAULT_LEVEL_STREAMS_HPP_INCLUDED

#include <fcppt/io/ostream.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/detail/symbol.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Constructs the default level streams

\ingroup fcpptlog

Each level stream will log to \a stream and get a corresponding \link
fcppt::log::format::default_level \endlink as its formatter.

\return A stream array consisting of a default stream for each level
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::log::level_stream_array
default_level_streams(
	fcppt::io::ostream &stream
);

}
}

#endif
