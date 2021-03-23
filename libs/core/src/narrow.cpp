//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/narrow.hpp>
#include <fcppt/narrow_locale.hpp>
#include <fcppt/optional_std_string.hpp>
#include <fcppt/string_conv_locale.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string_view>
#include <fcppt/config/external_end.hpp>

fcppt::optional_std_string fcppt::narrow(std::wstring_view const &_string)
{
  return fcppt::narrow_locale(_string, fcppt::string_conv_locale());
}
