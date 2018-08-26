//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NARROW_HPP_INCLUDED
#define FCPPT_NARROW_HPP_INCLUDED

#include <fcppt/string_conv_locale.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Converts a std::wstring to std::string

\ingroup fcpptstring

Converts \a _string to std::string using \a _locale.
*/
FCPPT_DETAIL_SYMBOL
std::string
narrow(
	std::wstring const &_string,
	std::locale const &_locale
		= fcppt::string_conv_locale()
);

}

#endif
