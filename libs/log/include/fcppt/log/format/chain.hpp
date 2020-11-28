//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_FORMAT_CHAIN_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_CHAIN_HPP_INCLUDED

#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/format/optional_function_fwd.hpp>

namespace fcppt
{
namespace log
{
namespace format
{
/**
\brief Composes two formatters

\ingroup fcpptlog

Creates a formatter that composes \a parent and \a child in the following way:
If \a parent and \a child are not nothing, their functions are composed
(<code>parent (.) child</code>). Otherwise, if \a parent is not nothing, \a
parent is returned. Otherwise, \a child is returned.
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::log::format::optional_function chain(
    fcppt::log::format::optional_function const &parent,
    fcppt::log::format::optional_function const &child);

}
}
}

#endif
