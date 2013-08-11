//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FROM_STD_WSTRING_LOCALE_HPP_INCLUDED
#define FCPPT_FROM_STD_WSTRING_LOCALE_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Convert from std::wstring to fcppt::string using a custom locale
\ingroup fcpptstring


See the \link fcpptstring string module description \endlink for more
information about this function.
*/
FCPPT_SYMBOL
fcppt::string
from_std_wstring_locale(
	std::wstring const &,
	std::locale const &
);

}

#endif
