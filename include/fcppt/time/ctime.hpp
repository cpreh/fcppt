//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_CTIME_HPP_INCLUDED
#define FCPPT_TIME_CTIME_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace time
{

/// A wrapper around std::ctime
/**
 * Converts the given time_t into a string
*/
FCPPT_SYMBOL
string const
ctime(
	std::time_t
);

}
}

#endif
