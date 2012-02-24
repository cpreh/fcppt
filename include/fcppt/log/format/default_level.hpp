//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_DEFAULT_LEVEL_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_DEFAULT_LEVEL_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/format/function.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

/**
\brief Creates a default formatter for a level stream

\ingroup fcpptlog

Creates a default formatter for a level stream with the level of \a level.
This formatter prints the level's string in front as obtained by \link
fcppt::log::level_to_string \endlink. It also appends a newline at the end.

\param level The level to print

\return A new formatter printing the level in front
*/
FCPPT_SYMBOL
fcppt::log::format::function const
default_level(
	fcppt::log::level::type level
);

}
}
}

#endif
