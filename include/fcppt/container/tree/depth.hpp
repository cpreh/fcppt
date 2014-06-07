//          Copyright Carl Philipp Reh 2009 - 2014.
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

	size_type result =
		0u;

	for(
		typename tree_type::const_reference ref : _tree)
		result =
			std::max(
				result,
				fcppt::container::tree::depth(
					ref));

	return
		1u + result;
}
}
}
}

#endif
