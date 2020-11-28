//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/pre_order.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

template class fcppt::container::tree::object<int>;

TEST_CASE("container::tree::pre_order", "[container],[tree]")
{
  using i_tree = fcppt::container::tree::object<int>;

  i_tree tree(1);

  fcppt::reference<i_tree> const child_1{tree.push_back(2)};

  child_1.get().push_back(3);

  child_1.get().push_back(4);

  tree.push_back(5);

  tree.push_back(6);

  using traversal_type = fcppt::container::tree::pre_order<i_tree const>;

  traversal_type const trav(tree);

  REQUIRE(std::distance(trav.begin(), trav.end()) == 6);

  traversal_type::iterator it(trav.begin());

  CHECK(it->value() == 1);

  ++it;

  CHECK(it->value() == 2);

  ++it;

  CHECK(it->value() == 3);

  ++it;

  CHECK(it->value() == 4);

  ++it;

  CHECK(it->value() == 5);

  ++it;

  CHECK(it->value() == 6);

  ++it;

  CHECK(it == trav.end());
}
