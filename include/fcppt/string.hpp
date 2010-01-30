//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRING_HPP_INCLUDED
#define FCPPT_STRING_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <string>

namespace fcppt
{

/**
 * @brief The string type used for text.
 *
 * @see char_type
*/
typedef std::basic_string<
	char_type
> string;

}

#endif
