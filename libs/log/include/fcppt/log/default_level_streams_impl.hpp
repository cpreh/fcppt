//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_DEFAULT_LEVEL_STREAMS_IMPL_HPP_INCLUDED
#define FCPPT_LOG_DEFAULT_LEVEL_STREAMS_IMPL_HPP_INCLUDED

#include <fcppt/log/standard_level_stream_array.hpp>
#include <fcppt/log/detail/symbol.hpp>

namespace fcppt::log
{
/**
\brief Constructs derived classes of the default level streams.

\ingroup fcpptlog
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::log::standard_level_stream_array default_level_streams_impl();
}

#endif
