//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_WIDEN_HPP_INCLUDED
#define FCPPT_WIDEN_HPP_INCLUDED

#include <fcppt/string_conv_locale.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <string_view>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Converts a std::string to std::wstring

\ingroup fcpptstring

Converts \a _string to std::wstring using \a _locale.
*/
FCPPT_DETAIL_SYMBOL
std::wstring
widen(
	std::string_view const &,
	std::locale const &
		= fcppt::string_conv_locale()
);

}

#endif
