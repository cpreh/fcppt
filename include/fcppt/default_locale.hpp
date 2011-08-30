//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DEFAULT_LOCALE_HPP_INCLUDED
#define FCPPT_DEFAULT_LOCALE_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

/// Returns the default locale set on the system instead of the C locale
FCPPT_SYMBOL
std::locale const
default_locale();

}

#endif
