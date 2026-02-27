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
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::tree copy", "[container],[tree]")
{
  using i_tree = fcppt::container::tree::object<int>;

  i_tree head(1);

  head.push_back(2);

  head.push_back(3);

  i_tree const head2(head);

  CHECK(head2.value() == 1);

  REQUIRE(head2.children().size() == 2U);

  fcppt::optional::maybe(
      head2.front(),
      [] { CHECK(false); },
      [&head2](fcppt::reference<i_tree const> const _front) {
        CHECK(_front.get().value() == 2);

        fcppt::optional::maybe(
            _front.get().parent(),
            [] { CHECK(false); },
            [&head2](fcppt::reference<i_tree const> const _parent) {
              CHECK(&_parent.get() == &head2);
            });
      });

  fcppt::optional::maybe(
      head2.back(),
      [] { CHECK(false); },
      [&head2](fcppt::reference<i_tree const> const _back) {
        CHECK(_back.get().value() == 3);

        fcppt::optional::maybe(
            _back.get().parent(),
            [] { CHECK(false); },
            [&head2](fcppt::reference<i_tree const> const _parent) {
              CHECK(&_parent.get() == &head2);
            });
      });
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
