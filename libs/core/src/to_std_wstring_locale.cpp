//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/public_config.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/to_std_wstring_locale.hpp>
#if defined(FCPPT_NARROW_STRING)
#include <fcppt/widen_locale.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>

std::wstring fcppt::to_std_wstring_locale(
    fcppt::string_view const _input,
#if defined(FCPPT_NARROW_STRING)
    std::locale const &_locale
#else
    std::locale const &
#endif
)
{
#if defined(FCPPT_NARROW_STRING)
  return fcppt::widen_locale(_input, _locale);
#else
  return std::wstring{_input};
#endif
}
