//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_COPY_TREE_VALUE_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_COPY_TREE_VALUE_HPP_INCLUDED

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>

namespace fcppt
{
namespace container
{
namespace tree
{

/// Default implementation for copying tree values
/**
 * @param _value The value to copy (as obtained by tree::object::value
 * @return An fcppt::unique_ptr<T> that holds the copied value
 *
 * This function is meant to serve as a customization point via ADL.
 * If you attempt to copy a tree::object<tree::ptr_value<T> > then
 * this function will be called for every value that is held by each node.
 *
 * Example:
 *
 * namespace mine
 * {
 *   struct mytype
 *   {
 *      ...
 *   };
 *
 *   fcppt::unique_ptr<
 *     mtype
 *   >
 *   copy_tree_value(
 *      mytype const &
 *   );
 * }
*/
template<
	typename T
>
fcppt::unique_ptr<
	T
>
copy_tree_value(
	T const &_value
)
{
	return	
		fcppt::make_unique_ptr<
			T
		>(
			_value
		);
}

}
}
}

#endif
