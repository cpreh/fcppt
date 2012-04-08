//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BACKTRACE_STACK_FRAME_HPP_INCLUDED
#define FCPPT_BACKTRACE_STACK_FRAME_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace backtrace
{
typedef
std::vector<fcppt::string>
stack_frame;
}
}

#endif
