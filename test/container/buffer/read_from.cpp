//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/container/buffer/object.hpp>
#include <fcppt/container/buffer/read_from.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("container::buffer::read_from", "[container],[buffer]")
{
  using buffer_type = fcppt::container::buffer::object<int>;

  buffer_type const result{fcppt::container::buffer::read_from<buffer_type>(
      10U, [](buffer_type::pointer const _data, buffer_type::size_type) {
        _data[0] = 10;

        _data[1] = 20;

        return 2U;
      })};

  CHECK(result.write_size() == 8U);

  REQUIRE(result.read_size() == 2U);

  CHECK(result[0] == 10);

  CHECK(result[1] == 20);
}

FCPPT_CATCH_END
