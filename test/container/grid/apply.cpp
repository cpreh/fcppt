//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/cast/size.hpp>
#include <fcppt/container/grid/apply.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/output.hpp>
#include <fcppt/container/grid/static_row.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("container::grid::apply", "[container],[grid]")
{
  using string_grid = fcppt::container::grid::object<std::string, 2>;

  using uint_grid = fcppt::container::grid::object<unsigned, 2>;

  uint_grid const grid1(uint_grid::dim{2U, 3U}, [](uint_grid::pos const &_pos) {
    return fcppt::cast::size<unsigned>(
        fcppt::math::vector::at<0>(_pos) + fcppt::math::vector::at<1>(_pos));
  });

  string_grid const grid2(string_grid::dim{2U, 3U}, [](string_grid::pos const &_pos) {
    return std::to_string(fcppt::math::vector::at<0>(_pos) + fcppt::math::vector::at<1>(_pos));
  });

  auto const function([](unsigned const _value1, std::string const &_value2) {
    return std::to_string(_value1) + _value2;
  });

  string_grid const result(fcppt::container::grid::apply(function, grid1, grid2));

  CHECK(
      result == string_grid{
                    fcppt::container::grid::static_row(std::string{"00"}, std::string{"11"}),
                    fcppt::container::grid::static_row(std::string{"11"}, std::string{"22"}),
                    fcppt::container::grid::static_row(std::string{"22"}, std::string{"33"})});

  CHECK(fcppt::container::grid::apply(function, grid1, string_grid()) == string_grid{});
}
