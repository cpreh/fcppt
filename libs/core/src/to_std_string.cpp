//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/optional_std_string.hpp>
#include <fcppt/public_config.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/to_std_string.hpp>
#if !defined(FCPPT_NARROW_STRING)
#include <fcppt/string_conv_locale.hpp>
#include <fcppt/to_std_string_locale.hpp>
#endif
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

fcppt::optional_std_string fcppt::to_std_string(fcppt::string_view const _input)
{
  return
#if !defined(FCPPT_NARROW_STRING)
      fcppt::to_std_string_locale(_input, fcppt::string_conv_locale())
#else
      fcppt::optional_std_string
  {
    std::string { _input }
  }
#endif
          ;
}
