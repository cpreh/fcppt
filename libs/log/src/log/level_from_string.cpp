//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/enum/from_string.hpp>
#include <fcppt/log/level_from_string.hpp>
#include <fcppt/log/level_strings.hpp>
#include <fcppt/log/optional_level.hpp>

fcppt::log::optional_level fcppt::log::level_from_string(fcppt::string const &_name)
{
  return fcppt::enum_::from_string<fcppt::log::level>(_name);
}
