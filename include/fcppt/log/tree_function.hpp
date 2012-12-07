//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_TREE_FUNCTION_HPP_INCLUDED
#define FCPPT_LOG_TREE_FUNCTION_HPP_INCLUDED

#include <fcppt/log/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace log
{

/**
\brief A function object used to manipulate logger state

\ingroup fcpptlog

This function object type can be used with a logger context to manipulate
loggers through \link fcppt::log::context::apply \endlink.
*/
typedef std::function<
	void (
		fcppt::log::object &
	)
> tree_function;

}
}

#endif
