//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/from_std_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/level_to_string.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/standard_level_stream.hpp>
#include <fcppt/log/detail/temporary_output.hpp>

fcppt::log::standard_level_stream::standard_level_stream(
    fcppt::io::ostream &_dest, fcppt::log::level const _level)
    : fcppt::log::level_stream{}, dest_{_dest}, level_{_level}
{
}

fcppt::log::standard_level_stream::~standard_level_stream() = default;

void fcppt::log::standard_level_stream::log(
    fcppt::log::detail::temporary_output const &_output,
    fcppt::log::location const &_location) const
{
  dest_.get() << _location.string() << FCPPT_TEXT(": ")
              << fcppt::from_std_string(fcppt::log::level_to_string(this->level_))
              << FCPPT_TEXT(": ") << _output.result() << FCPPT_TEXT('\n');

  dest_.get().flush();
}
