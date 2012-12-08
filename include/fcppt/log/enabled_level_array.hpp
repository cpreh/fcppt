//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_ENABLED_LEVEL_ARRAY_HPP_INCLUDED
#define FCPPT_LOG_ENABLED_LEVEL_ARRAY_HPP_INCLUDED

#include <fcppt/log/level.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace log
{

/**
\brief An array used to save which log levels are activated

\ingroup fcpptlog

An array of bool with the size \link fcppt::log::level::size \endlink. Each
entry corresponds to an enumerator from \link fcppt::log::level \endlink.
*/
typedef std::array<
	bool,
	static_cast<
		std::size_t
	>(
		fcppt::log::level::size
	)
> enabled_level_array;

}
}

#endif
