//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_GLOBAL_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_GLOBAL_CONTEXT_HPP_INCLUDED

#include <fcppt/log/context_fwd.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{

/// Returns fcppt's global logger context
FCPPT_SYMBOL context &
global_context();

}
}

#endif
