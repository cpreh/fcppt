//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_WIDEN_LOCALE_HPP_INCLUDED
#define FCPPT_WIDEN_LOCALE_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <string>
#include <string_view>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Converts a <code>std::string</code> to <code>std::wstring</code>, using a locale.

\ingroup fcpptstring

Converts \a _string to <code>std::wstring</code> using \a _locale.

\throw std::runtime_error If the conversion fails (which should not happen).
*/
FCPPT_DETAIL_SYMBOL
std::wstring widen_locale(std::string_view const &, std::locale const &);

}

#endif
