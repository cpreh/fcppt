//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OUTPUT_TO_STD_WSTRING_HPP_INCLUDED
#define FCPPT_OUTPUT_TO_STD_WSTRING_HPP_INCLUDED

#include <fcppt/insert_extract_locale.hpp>
#include <fcppt/output_to_std_wstring_locale.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Convert an arbitrary type to a std::wstring, using #fcppt::insert_extract_locale.

\ingroup fcpptstring

\see fcppt::extract_from_string
\see fcppt::output_to_string
\see fcppt::output_to_fcppt_string
\see fcppt::output_to_std_string
*/
template <typename Source>
inline std::wstring output_to_std_wstring(Source const &_source)
{
  return fcppt::output_to_std_wstring_locale(_source, fcppt::insert_extract_locale());
}

}

#endif
