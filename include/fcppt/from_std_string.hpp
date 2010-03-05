//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FROM_STD_STRING_HPP_INCLUDED
#define FCPPT_FROM_STD_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <string>

namespace fcppt
{

FCPPT_SYMBOL string const
from_std_string(
	std::string const &
);

}

#endif
