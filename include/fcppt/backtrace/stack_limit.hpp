//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BACKTRACE_STACK_LIMIT_HPP_INCLUDED
#define FCPPT_BACKTRACE_STACK_LIMIT_HPP_INCLUDED

#include <fcppt/strong_typedef.hpp>
#include <fcppt/backtrace/stack_frame.hpp>


namespace fcppt
{
namespace backtrace
{
FCPPT_MAKE_STRONG_TYPEDEF(
	backtrace::stack_frame::size_type,
	stack_limit);
}
}

#endif
