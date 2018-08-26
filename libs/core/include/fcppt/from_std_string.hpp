//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FROM_STD_STRING_HPP_INCLUDED
#define FCPPT_FROM_STD_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Convert from std::string to fcppt::string using fcppt::string_conv_locale
\ingroup fcpptstring

See the \link fcpptstring string module description \endlink for more
information about this function.
*/
FCPPT_DETAIL_SYMBOL
fcppt::string
from_std_string(
	std::string const &
);

}

#endif
