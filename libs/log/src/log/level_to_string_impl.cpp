//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/enum/to_string_case.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_to_string_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string_view>
#include <fcppt/config/external_end.hpp>

std::string_view
fcppt::enum_::to_string_impl<fcppt::log::level>::get(fcppt::log::level const _level)
{
#define LEVEL_CASE(level_name) FCPPT_ENUM_TO_STRING_CASE(fcppt::log::level, level_name)
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
  switch (_level)
  {
    LEVEL_CASE(verbose);
    LEVEL_CASE(debug);
    LEVEL_CASE(info);
    LEVEL_CASE(warning);
    LEVEL_CASE(error);
    LEVEL_CASE(fatal);
  }
  FCPPT_PP_POP_WARNING
  throw fcppt::enum_::make_invalid(_level);
}
