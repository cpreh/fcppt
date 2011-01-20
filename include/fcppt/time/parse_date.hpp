//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_PARSE_DATE_HPP_INCLUDED
#define FCPPT_TIME_PARSE_DATE_HPP_INCLUDED

#include <fcppt/io/istream.hpp>
#include <fcppt/symbol.hpp>
#include <ctime>

namespace fcppt
{
namespace time
{

/// Tries to parse a date from @a stream and put the result in @a result
/**
 * If the parsing is successful, the result will be placed in @result (tm_mday, tm_mon and tm_year)
 * Otherwise the failbit of @a stream will be set and @a result will be left untouched.
 * Note that this function will only touch a portion of the members of @a result.
 * You will have to set the other members to meaningful values yourself.
 * @return @a stream
*/
FCPPT_SYMBOL
io::istream &
parse_date(
	io::istream &stream,
	std::tm &result
);

}
}

#endif
