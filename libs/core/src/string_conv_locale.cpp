//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string_conv_locale.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <fcppt/config/external_end.hpp>

std::locale fcppt::string_conv_locale()
{
#ifdef __MINGW32__
  return std::locale();
#else
  return std::locale("");
#endif
}
