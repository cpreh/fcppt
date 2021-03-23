//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_FORMAT_PREFIX_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_PREFIX_HPP_INCLUDED

#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/format/prefix_string.hpp>

namespace fcppt
{
namespace log
{
namespace format
{
/**
\brief Creates a prefix formatter.

\ingroup fcpptlog

Creates a formatter that outputs \a prefix in front.
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::log::format::function prefix(fcppt::log::format::prefix_string const &prefix);

}
}
}

#endif
