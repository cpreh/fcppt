//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/algorithm/find_by_opt.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/catch/optional.hpp> // IWYU pragma: keep
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("algorithm find_by_opt", "[algorithm_find_by_opt]")
{
  using int_vector = std::vector<int>;

  int_vector const vec{1, 2, 3};

  using result_type = fcppt::optional::object<std::string>;

  CHECK(fcppt::algorithm::find_by_opt<std::string>(vec, [](int const _i) -> result_type {
          return (_i % 2 == 0) ? result_type(std::string("test")) : result_type();
        }) == result_type(std::string("test")));

  CHECK(fcppt::algorithm::find_by_opt<std::string>(vec, [](int const _i) -> result_type {
          return _i == 4 ? result_type(std::string("test")) : result_type();
        }) == result_type{});
}

// NOLINTEND(bugprone-throwing-static-initialization,clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
