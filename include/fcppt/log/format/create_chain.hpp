//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_CREATE_CHAIN_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_CREATE_CHAIN_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/log/format/function.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

/**
\brief Creates a chain formatter

\ingroup fcpptlog

Creates a formatter that behaves like \link fcppt::log::format::chain \endlink
called with \a parent and \a child. If one of the parameters is an empty
function, the other parameter will be returned.

\param parent The parent formatter. can be empty if \a child is not empty

\param child The child formatter. Can be empty if \a parent is not empty

\return A new formatter combining \a parent and \a child

\warning The behaviour is undefined if both parameters are empty
*/
FCPPT_SYMBOL
fcppt::log::format::function const
create_chain(
	fcppt::log::format::function const &parent,
	fcppt::log::format::function const &child
);

}
}
}

#endif
