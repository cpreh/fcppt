//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_CREATE_PREFIX_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_CREATE_PREFIX_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/log/symbol.hpp>
#include <fcppt/log/format/function.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

/**
\brief Creates a prefix formatter

\ingroup fcpptlog

Creates a formatter that output \a prefix in front.

\param prefix The prefix to print in front

\return A new formatter printing \a prefix in front
*/
FCPPT_LOG_SYMBOL
fcppt::log::format::function
create_prefix(
	fcppt::string const &prefix
);

}
}
}

#endif
