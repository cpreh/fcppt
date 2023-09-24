//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/strong_typedef_output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/cast/size.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/grid/map.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/container/grid/static_row.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("container::grid::map", "[container],[grid]")
{
  using string_grid = fcppt::container::grid::object<std::string, 2>;

  using uint_grid = fcppt::container::grid::object<unsigned, 2>;

  uint_grid const grid(uint_grid::dim{2U, 3U}, [](uint_grid::pos const &_pos) {
    return fcppt::cast::size<unsigned>(
        fcppt::math::vector::at<0>(_pos) + fcppt::math::vector::at<1>(_pos));
  });

  string_grid const result(fcppt::container::grid::map(
      grid, [](unsigned const _value) { return std::to_string(_value); }));

  CHECK(
      result == string_grid{
                    fcppt::container::grid::static_row(std::string{"0"}, std::string{"1"}),
                    fcppt::container::grid::static_row(std::string{"1"}, std::string{"2"}),
                    fcppt::container::grid::static_row(std::string{"2"}, std::string{"3"})});
}

TEST_CASE("container::grid::map move", "[container],[grid]")
{
  using uint_movable = fcppt::catch_::movable<unsigned>;

  FCPPT_DECLARE_STRONG_TYPEDEF(uint_movable, strong_result);

  using movable_grid = fcppt::container::grid::object<uint_movable, 2>;

  using strong_grid = fcppt::container::grid::object<strong_result, 2>;

  strong_grid const result(fcppt::container::grid::map(
      movable_grid(
          movable_grid::dim{3U, 2U},
          [](movable_grid::pos const &_pos) {
            return uint_movable{fcppt::cast::size<unsigned>(
                fcppt::math::vector::at<0>(_pos) + fcppt::math::vector::at<1>(_pos))};
          }),
      [](uint_movable &&_value) { return strong_result(std::move(_value)); }));

  CHECK(
      result == strong_grid{
                    fcppt::container::grid::static_row(
                        strong_result{uint_movable{0U}},
                        strong_result{uint_movable{1U}},
                        strong_result{uint_movable{2U}}),
                    fcppt::container::grid::static_row(
                        strong_result{uint_movable{1U}},
                        strong_result{uint_movable{2U}},
                        strong_result{uint_movable{3U}})});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
