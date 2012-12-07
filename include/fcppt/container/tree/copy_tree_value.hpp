//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_COPY_TREE_VALUE_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_COPY_TREE_VALUE_HPP_INCLUDED

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

/// Default implementation for copying tree values
/**
\ingroup fcpptcontainertree
\param _value The value to copy (as obtained by fcppt::container::tree::object::value)
\return An <code>fcppt::unique_ptr<T></code> that holds the copied value

This function is meant to serve as a customization point via ADL.
If you attempt to copy a <code>tree::%object<tree::ptr_value<T>></code> then
this function will be called for every value that is held by each node.

Example:

\code
namespace mine
{
  struct mytype
  {
     ...
  };

  std::unique_ptr<
    mtype
  >
  copy_tree_value(
     mytype const &
  );
}
\endcode
*/
template<
	typename T
>
std::unique_ptr<
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
