//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OUTPUT_TO_STRING_HPP_INCLUDED
#define FCPPT_OUTPUT_TO_STRING_HPP_INCLUDED

#include <fcppt/insert_extract_locale.hpp>
#include <fcppt/output_to_string_locale.hpp>
#include <fcppt/type_traits/is_string.hpp>

namespace fcppt
{
/**
\brief Convert an arbitrary type to a string, using #fcppt::insert_extract_locale.

\ingroup fcpptstring

\tparam Dest A string type, see fcppt::type_traits::is_string

\tparam Source The type to make into a string. Has to have an <code>operator&lt;&lt;</code> defined.

\see fcppt::extract_from_string
\see fcppt::output_to_std_string
\see fcppt::output_to_std_wstring
\see fcppt::output_to_fcppt_string
*/
template <typename Dest, typename Source>
inline Dest output_to_string(Source const &_source)
{
  static_assert(
      fcppt::type_traits::is_string<Dest>::value, "insert_ot_string must return a string");

  return fcppt::output_to_string_locale<Dest>(_source, fcppt::insert_extract_locale());
}

}

#endif
