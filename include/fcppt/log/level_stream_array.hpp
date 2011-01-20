//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_STREAM_ARRAY_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_STREAM_ARRAY_HPP_INCLUDED

#include <fcppt/log/level_stream_ptr.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/container/array_fwd.hpp>

namespace fcppt
{
namespace log
{

/// An array of level streams with the size level::size
typedef fcppt::container::array<
	level_stream_ptr,
	level::size
> level_stream_array;

}
}

#endif
