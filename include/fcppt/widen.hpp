//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_WIDEN_HPP_INCLUDED
#define FCPPT_WIDEN_HPP_INCLUDED

#include <fcppt/string_conv_locale.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/// convert an std::string to std::wstring
FCPPT_SYMBOL
std::wstring
widen(
	std::string const &,
	std::locale const &
		= fcppt::string_conv_locale()
);

}

#endif
