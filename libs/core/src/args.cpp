//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args.hpp>
#include <fcppt/args_char.hpp>
#include <fcppt/args_vector.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/detail/main_wchar.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#ifndef FCPPT_DETAIL_MAIN_WCHAR
#include <fcppt/from_std_string.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <ranges>
#ifdef FCPPT_DETAIL_MAIN_WCHAR
#include <string>
#else
#include <string_view>
#endif
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

fcppt::args_vector fcppt::args(int const _argc, fcppt::args_char const *const *const _argv)
{
  return fcppt::algorithm::map<fcppt::args_vector>(
      std::ranges::subrange{
          _argv,
          _argv + _argc // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
          },
      [](fcppt::args_char const *const _arg) {
        return
#ifdef FCPPT_DETAIL_MAIN_WCHAR
            // fcppt::string is std::wstring in this case
            std::basic_string<fcppt::args_char>{_arg};
#else
            fcppt::from_std_string(std::string_view{_arg});
#endif
      });
}

FCPPT_PP_POP_WARNING
