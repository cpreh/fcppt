//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_FROM_STRING_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_FROM_STRING_HPP_INCLUDED

#include <fcppt/log/level.hpp>
#include <fcppt/string.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{

FCPPT_SYMBOL level::type
level_from_string(
	string const &
);

}
}

#endif

