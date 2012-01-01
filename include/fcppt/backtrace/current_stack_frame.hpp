//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BACKTRACE_CURRENT_STACK_FRAME_HPP_INCLUDED
#define FCPPT_BACKTRACE_CURRENT_STACK_FRAME_HPP_INCLUDED

#include <fcppt/symbol.hpp>
#include <fcppt/backtrace/stack_frame.hpp>
#include <fcppt/backtrace/stack_limit.hpp>


namespace fcppt
{
namespace backtrace
{
FCPPT_SYMBOL
backtrace::stack_frame const
current_stack_frame(
	backtrace::stack_limit const &);
}
}

#endif
