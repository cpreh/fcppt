//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/tree/comparison.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::tree equal", "[container],[tree]")
{
  using ui_tree = fcppt::container::tree::object<unsigned>;

  ui_tree tree1{1};

  tree1.push_back(2);

  ui_tree tree2{1};

  tree2.push_back(2);

  CHECK(tree1 == tree2);

  tree2.push_back(3);

  CHECK(tree1 != tree2);
}

FCPPT_CATCH_END
