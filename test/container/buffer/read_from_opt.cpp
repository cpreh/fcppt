//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/literal.hpp>
#include <fcppt/container/buffer/object.hpp>
#include <fcppt/container/buffer/read_from_opt.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("container::buffer::read_from_opt", "[container],[buffer]")
{
  using buffer_type = fcppt::container::buffer::object<int>;

  CHECK_FALSE(fcppt::container::buffer::read_from_opt<buffer_type>(
                  10U,
                  [](buffer_type::pointer, buffer_type::size_type) {
                    return fcppt::optional::object<buffer_type::size_type>();
                  })
                  .has_value());

  CHECK(fcppt::container::buffer::read_from_opt<buffer_type>(
            10U,
            [](buffer_type::pointer, buffer_type::size_type) {
              return fcppt::optional::make(fcppt::literal<buffer_type::size_type>(0U));
            })
            .has_value());
}
