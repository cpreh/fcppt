//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cyclic_iterator.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("cyclic_iterator array", "[cyclic_iterator]")
{
  using int3_array = fcppt::array::object<int, 3>;

  int3_array const array{1, 2, 3};

  using iterator = fcppt::cyclic_iterator<int3_array::const_iterator>;

  iterator const start(array.begin(), iterator::boundary{array.begin(), array.end()});

  iterator test(start);

  REQUIRE(*test == 1);

  ++test;

  REQUIRE(*test == 2);

  ++test;

  REQUIRE(*test == 3);

  ++test;

  REQUIRE(*test == 1);

  REQUIRE(test.get() == array.begin());

  --test;

  REQUIRE(*test == 3);

  REQUIRE(test.get() == std::prev(array.end()));

  --test;

  REQUIRE(*test == 2);

  test += 2;

  REQUIRE(*test == 1);

  test -= 1;

  REQUIRE(*test == 3);

  test -= 300;

  REQUIRE(*test == 3);

  ++test;

  REQUIRE(test == start);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
