//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/from_std_wstring_locale.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/public_config.hpp>
#include <fcppt/string.hpp>
#if defined(FCPPT_NARROW_STRING)
#include <fcppt/narrow_locale.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string_view>
#include <fcppt/config/external_end.hpp>

fcppt::optional_string fcppt::from_std_wstring_locale(
    std::wstring_view const &_input,
#if defined(FCPPT_NARROW_STRING)
    std::locale const &_locale
#else
    std::locale const &
#endif
)
{
#if defined(FCPPT_NARROW_STRING)
  return fcppt::narrow_locale(_input, _locale);
#else
  return fcppt::optional_string{fcppt::string{_input}};
#endif
}
