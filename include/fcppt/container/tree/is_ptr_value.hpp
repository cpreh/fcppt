//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_IS_PTR_VALUE_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_IS_PTR_VALUE_HPP_INCLUDED

#include <fcppt/container/tree/ptr_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace tree
{

/**
\brief A meta function testing if the tree's value_type has noncopyable semantics
\ingroup fcpptcontainertree
*/
template<
	typename T
>
struct is_ptr_value
:
boost::false_type
{
};

/**
\brief A meta function testing if the tree's value_type has noncopyable semantics
\ingroup fcpptcontainertree
*/
template<
	typename T
>
struct is_ptr_value<
	tree::ptr_value<
		T
	>
>
:
boost::true_type
{
};

}
}
}

#endif
