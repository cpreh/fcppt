//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_GMTIME_HPP_INCLUDED
#define FCPPT_TIME_GMTIME_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace time
{

/**
\brief A wrapper around <code>%std::gmtime</code>

\ingroup fcppttime

Converts \a time to an <code>%std::tm</code> using <code>%std::gmtime</code>.

\param time The time to convert
*/
FCPPT_DETAIL_SYMBOL
std::tm const
gmtime(
	std::time_t time
);

}
}

#endif
