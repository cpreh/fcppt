//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_TREE_FUNCTION_HPP_INCLUDED
#define FCPPT_LOG_TREE_FUNCTION_HPP_INCLUDED

#include <fcppt/function/object_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>


namespace fcppt
{
namespace log
{

typedef function::object<
	void (
		log::object &
	)
> tree_function;

}
}

#endif
