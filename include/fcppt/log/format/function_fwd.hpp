//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_FUNCTION_FWD_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_FUNCTION_FWD_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/function/object_fwd.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

/**
\brief A formatter function object

This object gets a string from which it returns a new string
*/
typedef fcppt::function::object<
	fcppt::string const (
		fcppt::string const &
	)
> function;

}
}
}

#endif
