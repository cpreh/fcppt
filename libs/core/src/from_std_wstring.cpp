//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/from_std_wstring.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/public_config.hpp>
#ifdef FCPPT_NARROW_STRING
#include <fcppt/from_std_wstring_locale.hpp>
#include <fcppt/string_conv_locale.hpp>
#else
#include <fcppt/string.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <string_view>
#include <fcppt/config/external_end.hpp>

fcppt::optional_string fcppt::from_std_wstring(std::wstring_view const _input)
{
  return
#ifdef FCPPT_NARROW_STRING
      fcppt::from_std_wstring_locale(_input, fcppt::string_conv_locale())
#else
      fcppt::optional_string{fcppt::string{_input}}
#endif
          ;
}
