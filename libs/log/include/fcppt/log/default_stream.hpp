//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_DEFAULT_STREAM_HPP_INCLUDED
#define FCPPT_LOG_DEFAULT_STREAM_HPP_INCLUDED

#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>

namespace fcppt
{
namespace log
{
/**
\brief The default stream to use a log level

Log levels <code>verbose</code> through <code>warning</code> log to #fcppt::io::clog,
and log levels <code>error</code> and <code>fatal</code> log to #fcppt::io::cerr.
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::io::ostream &default_stream(fcppt::log::level);

}
}

#endif
