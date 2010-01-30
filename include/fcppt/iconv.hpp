//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ICONV_HPP_INCLUDED
#define FCPPT_ICONV_HPP_INCLUDED

#include <fcppt/config.h>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <string>

namespace fcppt
{

/**
 * @brief Converts from std::string to fcppt::string or vice versa
*/
#ifndef FCPPT_NARROW_STRING
FCPPT_SYMBOL string const
iconv(
	std::string const &input
);

FCPPT_SYMBOL std::string const
iconv(
	string const &input
);
#else
FCPPT_SYMBOL string const
iconv(
	string const &
);
#endif

}

#endif
