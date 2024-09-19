//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/reference_impl.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::tree swap", "[container],[tree]")
{
  using i_tree = fcppt::container::tree::object<int>;

  i_tree tree1(1);

  tree1.push_back(2);

  i_tree tree2(3);

  swap(tree1, tree2);

  CHECK(tree1.value() == 3);

  CHECK(tree2.value() == 1);

  CHECK_FALSE(tree2.empty());

  fcppt::optional::maybe(
      tree2.front(),
      [] { CHECK(false); },
      [](fcppt::reference<i_tree> const _tree) { CHECK(_tree.get().value() == 2); });
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
