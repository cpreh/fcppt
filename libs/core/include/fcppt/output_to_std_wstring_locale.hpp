//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OUTPUT_TO_STD_WSTRING_LOCALE_HPP_INCLUDED
#define FCPPT_OUTPUT_TO_STD_WSTRING_LOCALE_HPP_INCLUDED

#include <fcppt/output_to_string_locale.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Convert an arbitrary type to a std::wstring, using a custom locale.

\ingroup fcpptstring

\see fcppt::extract_from_string
\see fcppt::output_to_string
\see fcppt::output_to_fcppt_string
\see fcppt::output_to_std_string
*/
template <typename Source>
std::wstring output_to_std_wstring_locale(Source const &_source, std::locale const &_locale)
{
  return fcppt::output_to_string_locale<std::wstring>(_source, _locale);
}

}

#endif
