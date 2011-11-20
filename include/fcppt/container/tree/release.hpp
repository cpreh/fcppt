//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_RELEASE_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_RELEASE_HPP_INCLUDED

#include <fcppt/unique_ptr.hpp>
#include <fcppt/container/tree/is_ptr_value.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

/**
\brief Releases the held value of a tree node and returns it as a <code>unique_ptr</code>

\note This only works for noncopyable trees

Example:
\snippet container/tree_ptr.cpp tree_ptr_release

\ingroup fcpptcontainertree
*/
template<
	typename T
>
typename boost::enable_if<
	tree::is_ptr_value<
		T
	>,
	fcppt::unique_ptr<
		typename T::type
	>
>::type
release(
	tree::object<
		T
	> &_tree
)
{
	return _tree.holder().release();
}

}
}
}

#endif
