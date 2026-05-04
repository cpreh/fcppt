//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/container/tree/make_to_root.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/to_root.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::tree::make_to_root", "[container],[tree]")
{
  using i_tree = fcppt::container::tree::object<int>;

  i_tree const tree{
      1,
      i_tree::child_list{
          i_tree{2, i_tree::child_list{i_tree{3}}}, i_tree{4, i_tree::child_list{i_tree{5}}}}};

  auto const copy_values{
      [](fcppt::container::tree::to_root<i_tree const> const &_tree) -> std::vector<int>
      {
        return fcppt::algorithm::map<std::vector<int>>(
            _tree, [](i_tree const &_ref) -> int { return _ref.value(); });
      }};

  CHECK(
      copy_values(fcppt::container::tree::make_to_root(tree)) ==
      std::vector<int>{1});

  CHECK(
      copy_values(fcppt::container::tree::make_to_root(*tree.begin())) ==
      std::vector<int>{2, 1});

  CHECK(
      copy_values(fcppt::container::tree::make_to_root(*tree.begin()->begin())) ==
      std::vector<int>{3, 2, 1});

  CHECK(
      copy_values(fcppt::container::tree::make_to_root(*std::next(tree.begin()))) ==
      std::vector<int>{4, 1});

  CHECK(
      copy_values(fcppt::container::tree::make_to_root(*std::next(tree.begin())->begin())) ==
      std::vector<int>{5, 4, 1});
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
