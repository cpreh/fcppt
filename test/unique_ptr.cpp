//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

TEST_CASE("unique_ptr object", "[smartptr]")
{
  using int_unique_ptr = fcppt::unique_ptr<int>;

  int_unique_ptr ptr{fcppt::make_unique_ptr<int>(2)};

  CHECK(*ptr == 2);

  int_unique_ptr ptr2{std::move(ptr)};

  CHECK(*ptr2 == 2);

  int_unique_ptr ptr3{fcppt::make_unique_ptr<int>(1)};

  CHECK(*ptr3 == 1);

  ptr3 = std::move(ptr2);

  CHECK(*ptr3 == 2);
}
