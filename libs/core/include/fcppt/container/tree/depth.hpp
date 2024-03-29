//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_TREE_DEPTH_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_DEPTH_HPP_INCLUDED

#include <fcppt/algorithm/fold.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::tree
{
template <typename Value>
typename fcppt::container::tree::object<Value>::size_type
depth(fcppt::container::tree::object<Value> const &_tree)
{
  using tree_type = fcppt::container::tree::object<Value>;

  using size_type = typename tree_type::size_type;

  return fcppt::algorithm::fold(
             _tree.children(),
             size_type{0U},
             [](tree_type const &_ref, size_type const _result) {
               return std::max(_result, fcppt::container::tree::depth(_ref));
             }) +
         1U;
}

}

#endif
