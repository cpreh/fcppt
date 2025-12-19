//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/loop_break_tuple.hpp> // IWYU pragma: keep
#include <fcppt/algorithm/map_optional.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/either/failure_opt.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("algorithm map_optional", "[algorithm_map_optional]")
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

TEST_CASE("algorithm map_optional tuple", "[algorithm_map_optional]")
{
  CHECK(
      fcppt::algorithm::map_optional<std::vector<std::string>>(
          fcppt::tuple::make(
              fcppt::either::make_failure<int>(std::string{"test1"}),
              fcppt::either::make_failure<float>(std::string{"test2"})),
          [](auto const &_either) { return fcppt::either::failure_opt(_either); }) ==
      std::vector<std::string>{std::string{"test1"}, std::string{"test2"}});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
