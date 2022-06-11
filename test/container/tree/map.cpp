//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/tree/map.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::tree::map", "[container],[tree]")
{
  using int_tree = fcppt::container::tree::object<int>;

  using int_unique_ptr = fcppt::unique_ptr<int>;

  using int_unique_ptr_tree = fcppt::container::tree::object<int_unique_ptr>;

  int_tree test(1);

  test.push_back(2);

  auto const result(fcppt::container::tree::map<int_unique_ptr_tree>(
      test, [](int const _value) { return fcppt::make_unique_ptr<int>(_value); }));

  CHECK(*result.value() == 1);

  fcppt::optional::maybe(
      result.back(),
      [] { CHECK(false); },
      [](fcppt::reference<int_unique_ptr_tree const> const _ref) {
        CHECK(2 == *_ref.get().value());
      });
}

FCPPT_CATCH_END
