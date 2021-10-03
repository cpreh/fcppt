//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/array/init.hpp>
#include <fcppt/array/object.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("array::init", "[array]")
{
  using movable = fcppt::catch_::movable<std::size_t>;

  using movable_2_array = fcppt::array::object<movable, 2>;

  CHECK(
      fcppt::array::init<movable_2_array>(
          []<std::size_t Index>(std::integral_constant<std::size_t, Index>)
          { return movable{Index}; }) == movable_2_array{movable{0U}, movable{1U}});
}

FCPPT_CATCH_END
