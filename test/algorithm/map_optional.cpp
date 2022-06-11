//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/map_optional.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("algorithm map_optional", "[algorithm_map_optional]", )
{
  using int_vector = std::vector<int>;

  using int_movable = fcppt::catch_::movable<int>;

  using int_movable_vector = std::vector<int_movable>;

  CHECK(
      fcppt::algorithm::map_optional<int_movable_vector>(int_vector{1, 2, 3}, [](int const _value) {
        using optional_int_movable = fcppt::optional::object<int_movable>;

        return _value == 1 ? optional_int_movable{int_movable{_value}} : optional_int_movable{};
      }) == fcppt::container::make<int_movable_vector>(int_movable{1}));
}

FCPPT_CATCH_END
