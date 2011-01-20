//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_STRING_ARRAY_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_STRING_ARRAY_HPP_INCLUDED

#include <fcppt/log/level.hpp>
#include <fcppt/container/array.hpp>
#include <fcppt/string.hpp>

namespace fcppt
{
namespace log
{

typedef fcppt::container::array<
	fcppt::string,
	fcppt::log::level::size
> level_string_array;

}
}

#endif
