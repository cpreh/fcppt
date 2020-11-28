//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/assert/optional_error.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("assert_optional_error", "[assert]")
{
  using optional_int = fcppt::optional::object<int>;

  using int_movable = fcppt::catch_::movable<int>;

  using optional_int_movable = fcppt::optional::object<int_movable>;

  CHECK(FCPPT_ASSERT_OPTIONAL_ERROR(optional_int{42}) == 42);

  CHECK(FCPPT_ASSERT_OPTIONAL_ERROR(optional_int_movable{int_movable{10}}).value() == 10);

  {
    optional_int_movable const opt{int_movable{42}};

    int_movable const &ref{FCPPT_ASSERT_OPTIONAL_ERROR(opt)};

    CHECK(ref.value() == 42);
  }
}
