//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_DETAIL_COPY_CHILDREN_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_DETAIL_COPY_CHILDREN_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/container/tree/object_fwd.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{
namespace detail
{

template<
	typename T
>
typename
fcppt::container::tree::object<
	T
>::child_list
copy_children(
	fcppt::container::tree::object<
		T
	> &_parent,
	typename fcppt::container::tree::object<
		T
	>::child_list const &_children
)
{
	typedef fcppt::container::tree::object<
		T
	> object;

	typename object::child_list result;

	for(
		auto const &child
		:
		_children
	)
	{
		result.push_back(
			child
		);

		result.back().parent(
			typename
			object::optional_ref(
				fcppt::make_ref(
					_parent
				)
			)
		);
	}

	return
		result;
}

}
}
}
}

#endif
