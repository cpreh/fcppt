//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("either::bind", "[either]")
{
  using either_int = fcppt::either::object<std::string, int>;

  using either_bool = fcppt::either::object<std::string, bool>;

  auto const bind_function([](int const _value) { return either_bool(_value > 10); });

  CHECK(
      fcppt::either::bind(either_int(std::string("test")), bind_function) ==
      either_bool{std::string{"test"}});

  CHECK(fcppt::either::bind(either_int(20), bind_function) == either_bool(true));

  CHECK(fcppt::either::bind(either_int(20), [](int) {
          return either_bool(std::string("failure"));
        }) == either_bool(std::string("failure")));
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
