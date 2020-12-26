//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/init.hpp>
#include <fcppt/array/object.hpp>
#include <fcppt/catch/array.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

TEST_CASE("array::init", "[array]")
{
  using movable = fcppt::catch_::movable<std::size_t>;

  using movable_2_array = fcppt::array::object<movable, 2>;

  CHECK(fcppt::array::init<movable_2_array>([](auto const _index) {
          return movable{_index()};
        }) == movable_2_array{movable{0U}, movable{1U}});
}
