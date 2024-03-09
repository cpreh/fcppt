//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/clog.hpp>
#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/log/default_stream.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

fcppt::io::ostream &fcppt::log::default_stream(fcppt::log::level const _level)
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)

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

  FCPPT_PP_POP_WARNING

  throw fcppt::enum_::make_invalid(_level);
}
