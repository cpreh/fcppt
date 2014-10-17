//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_CREATE_INSERTER_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_CREATE_INSERTER_HPP_INCLUDED

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
\brief Creates a formatter using \link fcppt::format \endlink

\ingroup fcpptlog

Creates a formatter that behaves like \link fcppt::log::format::inserter
\endlink called with \a format.

\param format The format string to use

\return A new formatter using \link fcppt::format \endlink with \a format
*/
FCPPT_LOG_SYMBOL
fcppt::log::format::function
create_inserter(
	fcppt::string const &format
);

}
}
}

#endif
