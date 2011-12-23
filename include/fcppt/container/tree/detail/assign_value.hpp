//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_DETAIL_ASSIGN_VALUE_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_DETAIL_ASSIGN_VALUE_HPP_INCLUDED

#include <fcppt/move.hpp>
#include <fcppt/scoped_ptr_impl.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace fcppt
{
namespace container
{
namespace tree
{
namespace detail
{

template<
	typename Value,
	typename Arg
>
void
assign_value(
	fcppt::scoped_ptr<
		Value
	> &_result,
	fcppt::unique_ptr<
		Arg
	> _arg
)
{
	_result.take(
		fcppt::move(
			_arg
		)
	);
}

template<
	typename Value,
	typename Arg
>
void
assign_value(
	Value &_result,
	Arg _arg
)
{
	_result = _arg;
}

}
}
}
}

#endif
