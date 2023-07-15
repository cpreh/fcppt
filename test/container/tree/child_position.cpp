//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/reference_impl.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/tree/child_position.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::tree::child_position", "[container],[tree]")
{
  using int_tree = fcppt::container::tree::object<int>;

  int_tree test{0, int_tree::child_list{int_tree{1}, int_tree{2}}};

  fcppt::optional::maybe(
      fcppt::optional::bind(
          test.front(),
          [&test](fcppt::reference<int_tree> const _child) {
            return fcppt::container::tree::child_position(test, _child.get());
          }),
      [] { CHECK(false); },
      [&test](int_tree::iterator const _pos) { CHECK(_pos == test.begin()); });
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
