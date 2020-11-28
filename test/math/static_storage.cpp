//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/math/detail/static_storage_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("math::detail::static_storage", "[math]")
{
  using storage_type = fcppt::math::detail::static_storage<int, 2>;

  {
    storage_type const const_storage{1, 2};

    CHECK(const_storage[0] == 1);

    CHECK(const_storage[1] == 2);

    CHECK(const_storage.data()[0] == 1);

    CHECK(const_storage.data()[1] == 2);
  }

  {
    storage_type storage{1, 2};

    storage[0] = 5;

    CHECK(storage[0] == 5);

    storage.data()[1] = 10;

    CHECK(storage.data()[1] == 10);
  }
}
