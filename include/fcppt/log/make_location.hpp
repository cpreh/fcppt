//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_MAKE_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_MAKE_LOCATION_HPP_INCLUDED

#include <fcppt/log/location.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/string.hpp>
#include <fcppt/char_type.hpp>

namespace fcppt
{
namespace log
{

/// Creates a location from a string with delimiters @a delim
FCPPT_SYMBOL location const
make_location(
	string const &name,
	char_type delim
);

}
}

#endif
