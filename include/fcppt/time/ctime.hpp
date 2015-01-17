//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_CTIME_HPP_INCLUDED
#define FCPPT_TIME_CTIME_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace time
{

/**
\brief A wrapper around <code>%std::ctime</code>

\ingroup fcppttime

Converts \a time into a string using <code>%std::ctime</code>.

\param time The time to convert into a string

\throw fcppt::time::exception if anything fails
*/
FCPPT_DETAIL_SYMBOL
fcppt::string
ctime(
	std::time_t time
);

}
}

#endif
