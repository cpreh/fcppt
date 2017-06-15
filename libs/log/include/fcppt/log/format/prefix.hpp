//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_PREFIX_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_PREFIX_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/log/detail/symbol.hpp>
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
FCPPT_LOG_DETAIL_SYMBOL
fcppt::log::format::function
prefix(
	fcppt::string const &prefix
);

}
}
}

#endif
