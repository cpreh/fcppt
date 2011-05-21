//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_OUTPUT_TM_HPP_INCLUDED
#define FCPPT_TIME_OUTPUT_TM_HPP_INCLUDED

#include <fcppt/io/ostream.hpp>
#include <fcppt/symbol.hpp>
#include <ctime>

namespace fcppt
{
namespace time
{

/// Outputs @a tm using the locale of the @a stream
/**
 * @return @a stream
*/
FCPPT_SYMBOL
io::ostream &
output_tm(
	io::ostream &stream,
	std::tm const &tm
);

}
}

#endif
