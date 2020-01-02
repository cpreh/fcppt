//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TO_STD_WSTRING_LOCALE_HPP_INCLUDED
#define FCPPT_TO_STD_WSTRING_LOCALE_HPP_INCLUDED

#include <fcppt/string_view.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Convert from #fcppt::string to std::wstring using a custom locale.
\ingroup fcpptstring

See \ref fcpptstring for more information about this function.
*/
FCPPT_DETAIL_SYMBOL
std::wstring
to_std_wstring_locale(
	fcppt::string_view const &,
	std::locale const &
);

}

#endif
