//          Copyright Carl Philipp Reh 2009 - 2011.
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

/// Constructs the default level streams
/**
 * They will get the default formatters that print a prefix for each level
*/
FCPPT_SYMBOL level_stream_array const
default_level_streams(
	io::ostream &
);

}
}

#endif
