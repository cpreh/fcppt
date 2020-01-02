//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_COMPARISON_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_COMPARISON_HPP_INCLUDED

#include <fcppt/container/tree/object_impl.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

/**
\brief Compares the values and recursively the values of the children
*/
template<
	typename T
>
bool
operator==(
	fcppt::container::tree::object<
		T
	> const &_a,
	fcppt::container::tree::object<
		T
	> const &_b
)
{
	return
		_a.value()
		==
		_b.value()
		&&
		_a.children()
		==
		_b.children();
}

/**
\brief Compares the values and recursively the values of the children
*/
template<
	typename T
>
bool
operator!=(
	fcppt::container::tree::object<
		T
	> const &_a,
	fcppt::container::tree::object<
		T
	> const &_b
)
{

	return
		!(_a == _b);
}

}
}
}

#endif

