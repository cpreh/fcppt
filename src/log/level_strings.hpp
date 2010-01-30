//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_STRINGS_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_STRINGS_HPP_INCLUDED

#include <fcppt/log/level.hpp>
#include <fcppt/tr1/array.hpp>
#include <fcppt/string.hpp>

namespace fcppt
{
namespace log
{

typedef std::tr1::array<
	fcppt::string,
	fcppt::log::level::size
> level_string_array;

extern level_string_array const level_strings;

}
}

#endif
