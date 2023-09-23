//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string_view.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/enum/from_string.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_from_string.hpp>
#include <fcppt/log/level_to_string_impl.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/log/optional_level.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

fcppt::log::optional_level fcppt::log::level_from_string(fcppt::string_view const _name)
{
  return fcppt::optional::bind(
      fcppt::to_std_string(_name),
      [](std::string const &_string)
      { return fcppt::enum_::from_string<fcppt::log::level>(_string); });
}
