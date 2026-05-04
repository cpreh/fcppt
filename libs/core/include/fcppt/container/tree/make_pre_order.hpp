//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_TREE_MAKE_PRE_ORDER_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_MAKE_PRE_ORDER_HPP_INCLUDED

#include <fcppt/container/tree/is_object.hpp>
#include <fcppt/container/tree/pre_order.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::tree
{
/**
\brief Creates a pre_order object

\ingroup fcpptcontainertree
*/
template <typename Tree>
inline fcppt::container::tree::pre_order<Tree> make_pre_order(Tree &_tree)
requires fcppt::container::tree::is_object<std::remove_cv_t<Tree>>::value
{
  return fcppt::container::tree::pre_order<Tree>{_tree};
}

}

#endif
