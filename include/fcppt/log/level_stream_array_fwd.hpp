//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_STREAM_ARRAY_FWD_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_STREAM_ARRAY_FWD_HPP_INCLUDED

#include <fcppt/container/enum_array_fwd.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/level_stream_fwd.hpp>


namespace fcppt
{
namespace log
{

/**
\brief An array used to save log level streams for every level

\ingroup fcpptlog

An array of \link fcppt::log::level_stream \endlink with the size \link
fcppt::log::level \endlink. Each entry corresponds to an enumerator from \link
fcppt::log::level \endlink.
*/
typedef
fcppt::container::enum_array<
	fcppt::log::level,
	fcppt::log::level_stream
>
level_stream_array;

}
}

#endif
