//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_STANDARD_LEVEL_STREAM_ARRAY_FWD_HPP_INCLUDED
#define FCPPT_LOG_STANDARD_LEVEL_STREAM_ARRAY_FWD_HPP_INCLUDED

#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/enum/array_fwd.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/standard_level_stream_fwd.hpp>

namespace fcppt::log
{
/**
\brief The array of standard level streams.

\ingroup fcpptlog
*/
using standard_level_stream_array =
    fcppt::enum_::array<fcppt::log::level, fcppt::unique_ptr<fcppt::log::standard_level_stream>>;
}

#endif
