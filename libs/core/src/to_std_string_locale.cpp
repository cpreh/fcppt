//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/optional_std_string.hpp>
#include <fcppt/public_config.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/to_std_string_locale.hpp>
#if !defined(FCPPT_NARROW_STRING)
#include <fcppt/narrow_locale.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>

fcppt::optional_std_string fcppt::to_std_string_locale(
    fcppt::string_view const &_input,
    std::locale const &
#if !defined(FCPPT_NARROW_STRING)
        _locale
#endif
)
{
#if !defined(FCPPT_NARROW_STRING)
  return fcppt::narrow_locale(_input, _locale);
#else
  return fcppt::optional_std_string{std::string{_input}};
#endif
}
