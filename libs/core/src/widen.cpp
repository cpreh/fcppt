//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string_conv_locale.hpp>
#include <fcppt/widen.hpp>
#include <fcppt/widen_locale.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <string_view>
#include <fcppt/config/external_end.hpp>

std::wstring fcppt::widen(std::string_view const _string)
{
  return fcppt::widen_locale(_string, fcppt::string_conv_locale());
}
