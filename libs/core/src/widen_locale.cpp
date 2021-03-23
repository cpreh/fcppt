//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/widen_locale.hpp>
#include <fcppt/impl/codecvt.hpp>
#include <fcppt/impl/codecvt_type.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <string_view>
#include <fcppt/config/external_end.hpp>

std::wstring fcppt::widen_locale(std::string_view const &_string, std::locale const &_locale)
{
  return fcppt::optional::to_exception(
      fcppt::impl::codecvt<wchar_t>(_string, _locale, &fcppt::impl::codecvt_type::in), [] {
        return fcppt::exception{FCPPT_TEXT("Failed to convert std::string to std::wstring.")};
      });
}
