//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_DEPTH_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_DEPTH_HPP_INCLUDED

#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{
template<typename Value>
typename
fcppt::container::tree::object<Value>::size_type
depth(
	fcppt::container::tree::object<Value> const &_tree)
{
	typedef
	fcppt::container::tree::object<Value>
	tree_type;

	typedef typename
	tree_type::size_type
	size_type;

	if(!_tree.has_value())
		return
			0u;

	size_type result =
		0u;

	for(
		typename tree_type::const_iterator it =
			_tree.begin();
		it != _tree.end();
		++it)
		result =
			std::max(
				result,
				fcppt::container::tree::depth(
					*it));

	return
		1u + result;
}
}
}
}

#endif
