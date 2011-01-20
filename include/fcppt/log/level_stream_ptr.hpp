//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_STREAM_PTR_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_STREAM_PTR_HPP_INCLUDED

#include <fcppt/log/level_stream_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace fcppt
{
namespace log
{

typedef fcppt::shared_ptr<
	level_stream
> level_stream_ptr;

}
}

#endif
