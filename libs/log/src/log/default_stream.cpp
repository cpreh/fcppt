//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/assert/unreachable.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/clog.hpp>
#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/log/default_stream.hpp>
#include <fcppt/log/level.hpp>

fcppt::io::ostream &fcppt::log::default_stream(fcppt::log::level const _level)
{
  switch (_level)
  {
  case fcppt::log::level::verbose:
  case fcppt::log::level::debug:
  case fcppt::log::level::info:
  case fcppt::log::level::warning:
    return fcppt::io::clog();
  case fcppt::log::level::error:
  case fcppt::log::level::fatal:
    return fcppt::io::cerr();
  }

  FCPPT_ASSERT_UNREACHABLE;
}
