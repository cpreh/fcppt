//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_STANDARD_LEVEL_STREAM_HPP_INCLUDED
#define FCPPT_LOG_STANDARD_LEVEL_STREAM_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/standard_level_stream_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/detail/temporary_output_fwd.hpp>

namespace fcppt::log
{
/**
\brief Logs to an fcppt::io::ostream.

\ingroup fcpptlog
*/
class standard_level_stream : public fcppt::log::level_stream
{
  FCPPT_NONMOVABLE(standard_level_stream);
public:
  /**
  \brief Constructs a level stream with a sink and a formatter
  */
  FCPPT_LOG_DETAIL_SYMBOL
  standard_level_stream(fcppt::io::ostream &, fcppt::log::level);

  FCPPT_LOG_DETAIL_SYMBOL
  ~standard_level_stream() override;

  FCPPT_LOG_DETAIL_SYMBOL
  void
  log(fcppt::log::detail::temporary_output const &, fcppt::log::location const &) const override;

private:
  fcppt::reference<fcppt::io::ostream> const dest_;

  fcppt::log::level const level_;
};
}

#endif
