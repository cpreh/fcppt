//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_CHAIN_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_CHAIN_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/log/format/function.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

/**
\brief Formats using two formatters in succession

\ingroup fcpptlog

Applies \a child to \a text, the result of which \a parent will be applied to.
<code>return parent(child(text));</code>.

\param parent The parent formatter. Must not be empty.

\param child The child formatter. Must not be empty.

\param text The text to format using \a parent and \a child.

\return The formatted text
*/
FCPPT_SYMBOL
fcppt::string const
chain(
	fcppt::log::format::function const &parent,
	fcppt::log::format::function const &child,
	fcppt::string const &text
);

}
}
}

#endif
