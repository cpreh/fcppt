//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_LOG_LEVEL_STRING_ARRAY_HPP_INCLUDED
#define FCPPT_SRC_LOG_LEVEL_STRING_ARRAY_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/container/array.hpp>
#include <fcppt/log/level.hpp>


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