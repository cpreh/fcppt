//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_LEVEL_STREAM_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_STREAM_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/log/level_stream_fwd.hpp> // IWYU pragma: keep
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/detail/temporary_output_fwd.hpp>

namespace fcppt::log
{
/**
\brief The stream for a logger level

\ingroup fcpptlog

Every logger object has a level stream for each logging levels. This class dictates
which sink and formatters should be used for a given level. Objects of this
class can be shared between several logger objects.
*/
class level_stream
{
  FCPPT_NONMOVABLE(level_stream);
public:
  level_stream();

  FCPPT_LOG_DETAIL_SYMBOL
  virtual ~level_stream();

  FCPPT_LOG_DETAIL_SYMBOL
  virtual void
  log(fcppt::log::detail::temporary_output const &, fcppt::log::location const &) const = 0;
};

}

#endif
