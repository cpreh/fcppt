//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_DEFAULT_LEVEL_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_DEFAULT_LEVEL_HPP_INCLUDED

#include <fcppt/log/format/const_object_ptr.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace log
{
namespace format
{

/// Creates the default formatter for the given log level
FCPPT_SYMBOL const_object_ptr const
default_level(
	level::type
);

}
}
}

#endif
