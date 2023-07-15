//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/map_failure.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("either::map_failure", "[either]")
{
  FCPPT_DECLARE_STRONG_TYPEDEF(int, int_strong);

  using either_string = fcppt::either::object<std::string, int_strong>;

  using either_char = fcppt::either::object<char, int_strong>;

  auto const map_function([](char const _value) { return std::string{_value}; });

  CHECK(fcppt::either::map_failure(either_char('0'), map_function).has_failure());

  CHECK(
      fcppt::either::map_failure(either_char('0'), map_function) ==
      either_string(std::string("0")));

  CHECK(
      fcppt::either::map_failure(either_char(int_strong{10}), map_function) ==
      either_string(int_strong{10}));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
