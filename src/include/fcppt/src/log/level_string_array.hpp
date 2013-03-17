//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_LOG_LEVEL_STRING_ARRAY_HPP_INCLUDED
#define FCPPT_SRC_LOG_LEVEL_STRING_ARRAY_HPP_INCLUDED

#include <fcppt/enum_size.hpp>
#include <fcppt/string.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace log
{

typedef std::array<
	fcppt::string,
	static_cast<
		std::size_t
	>(
		fcppt::enum_size<
			fcppt::log::level
		>::value
	)
> level_string_array;

}
}

#endif
