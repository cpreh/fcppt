//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_PARSE_TIME_HPP_INCLUDED
#define FCPPT_TIME_PARSE_TIME_HPP_INCLUDED

#include <fcppt/io/istream.hpp>
#include <fcppt/symbol.hpp>
#include <ctime>

namespace fcppt
{
namespace time
{

/// Tries to parse a time value from @a stream and put the result in @a result
/**
 * If the parsing is successful, the result will be placed in @result (tm_sec, tm_min and tm_hour)
 * Otherwise the failbit of @a stream will be set and @a result will be left untouched.
 * Note that this function will only touch a portion of the members of @a result.
 * You will have to set the other members to meaningful values yourself.
 * @return @a stream
*/
FCPPT_SYMBOL
io::istream &
parse_time(
	io::istream &stream,
	std::tm &result
);

}
}

#endif
