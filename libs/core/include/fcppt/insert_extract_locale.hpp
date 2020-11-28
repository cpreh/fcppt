//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_INSERT_EXTRACT_LOCALE_HPP_INCLUDED
#define FCPPT_INSERT_EXTRACT_LOCALE_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Returns the default locale to use when converting from or to strings.

This locale is the C locale.
This was chosen to avoid confusion when converting, for example, "300,100"
to int. Using the C locale, this will fail, since the string isn't completely
consumed. Using a German locale, however, this will return "300100", since ','
is the thousand separator for this locale.

\ingroup fcpptstring
*/
FCPPT_DETAIL_SYMBOL
std::locale insert_extract_locale();

}

#endif
