//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_LEVEL_STREAM_ARRAY_FWD_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_STREAM_ARRAY_FWD_HPP_INCLUDED

#include <fcppt/enum/array_fwd.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/level_stream_fwd.hpp>

namespace fcppt::log
{
/**
\brief An array used to save log level streams for every level

\ingroup fcpptlog

An array of #fcppt::log::level_stream with the size #fcppt::log::level.
Each entry corresponds to an enumerator from #fcppt::log::level.
*/
using level_stream_array = fcppt::enum_::array<fcppt::log::level, fcppt::log::level_stream>;

}

#endif
