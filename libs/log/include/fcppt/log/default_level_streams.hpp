//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_DEFAULT_LEVEL_STREAMS_HPP_INCLUDED
#define FCPPT_LOG_DEFAULT_LEVEL_STREAMS_HPP_INCLUDED

#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/detail/symbol.hpp>

namespace fcppt::log
{
/**
\brief Constructs the default level streams

\ingroup fcpptlog

Each level stream uses #fcppt::log::format::default_level as its
formatter and #fcppt::log::default_stream as its stream.
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::log::level_stream_array default_level_streams();

}

#endif
