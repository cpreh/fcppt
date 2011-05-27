//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_DETAIL_INIT_VALUE_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_DETAIL_INIT_VALUE_HPP_INCLUDED

#include <fcppt/container/tree/copy_tree_value.hpp>
#include <fcppt/scoped_ptr.hpp>
#include <fcppt/unique_ptr.hpp>

namespace fcppt
{
namespace container
{
namespace tree
{
namespace detail
{

template<
	typename Arg
>
fcppt::unique_ptr<
	Arg
>
init_value(
	fcppt::scoped_ptr<
		Arg
	> const &_arg
)
{
	return
		// intentionally an ADL call
		copy_tree_value(
			*_arg
		);
}

template<
	typename Arg
>
Arg const
init_value(
	Arg const &_arg
)
{
	return
		_arg;
}

}
}
}
}

#endif
