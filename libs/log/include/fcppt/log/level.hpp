//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_LEVEL_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_HPP_INCLUDED

#include <fcppt/log/level_fwd.hpp>

namespace fcppt::log
{
/**
\brief An enumeration for the available log levels.

\ingroup fcpptlog

Every enumerator state here represents a less serious log level than the next
one. For example, info is less serious than warning. size itself is not a
valid log level.

\ingroup fcpptlog
*/
enum class level
{
  /**
  \brief Used for verbose messages

  Verbose is the lowest log level, and so it should be used without any
  reserve.
  */
  verbose,
  /**
  \brief Used for debug messages

  The debug log level should be used whenever information is required
  that is only useful during debugging and would be too verbose otherwise.
  */
  debug,
  /**
  \brief Used for info messages

  The info log level should be used whenever information is required that
  is not too verbose. It is a good candidate to activate as default log
  level.
  */
  info,
  /**
  \brief Used for warning messages

  The warning log level should be used whenever something must be printed
  that is important for the user to read, but most of the time doesn't
  lead to any errors. It is not recommended to turn this off.
  */
  warning,
  /**
  \brief Used for error messages

  The error log level should be used whenever an error occurs, but it is
  still possible for the system to handle the situation. It is not
  recommended to turn this off.
  */
  error,
  /**
  \brief Used for fatal messages

  The fatal log level should be used whenever an error occurs that cannot
  be handled.
  */
  fatal,
  /**
  \brief The maximum value of the enumeration
  */
  fcppt_maximum = fatal
};

}

#endif
