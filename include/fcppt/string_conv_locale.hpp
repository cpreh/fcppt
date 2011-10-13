//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRING_CONV_LOCALE_HPP_INCLUDED
#define FCPPT_STRING_CONV_LOCALE_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

/// Returns the default locale to use when converting strings
FCPPT_SYMBOL
std::locale const
string_conv_locale();

}

#endif
