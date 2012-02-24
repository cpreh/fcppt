//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_MAKE_LOCATION_HPP_INCLUDED
#define FCPPT_LOG_MAKE_LOCATION_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/log/location.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Creates a location from a string with delimiters

\ingroup fcpptlog

Creates a location from \a text, splitting \a text using \a delim,
concatenating each obtained substring to the resulting location.

\param text The string to split

\param delim The delimiter to split with

\return A new location that consists of every substring of \a text split by \a
delim

\throw fcppt::log::exception if \a text doesn't contain any \a delim
*/
FCPPT_SYMBOL
fcppt::log::location const
make_location(
	fcppt::string const &text,
	fcppt::char_type delim
);

}
}

#endif
