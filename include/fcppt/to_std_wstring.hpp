//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TO_STD_WSTRING_HPP_INCLUDED
#define FCPPT_TO_STD_WSTRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Convert from fcppt::string to std::wstring using fcppt::string_conv_locale
\ingroup fcpptstring

See the \link fcpptstring string module description \endlink for more
information about this function.
*/
FCPPT_DETAIL_SYMBOL
std::wstring
to_std_wstring(
	fcppt::string const &
);

}

#endif
