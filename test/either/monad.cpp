//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/either/error.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/either/monad.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/monad/bind.hpp>
#include <fcppt/monad/constructor.hpp>
#include <fcppt/monad/inner_type.hpp>
#include <fcppt/monad/return.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
static_assert(std::is_same_v<
              fcppt::monad::constructor<fcppt::either::error<bool>, int>,
              fcppt::either::object<bool, int>>);

static_assert(std::is_same_v<fcppt::monad::inner_type<fcppt::either::object<bool, int>>, int>);

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("either monad return", "[either]")
{
  CHECK(
      fcppt::monad::return_<fcppt::either::error<std::string>>(1) ==
      fcppt::either::make_success<std::string>(1));
}

TEST_CASE("either monad bind", "[either]")
{
  using either_int = fcppt::either::object<std::string, int>;

  using either_bool = fcppt::either::object<std::string, bool>;

  auto const bind_function([](int const _value) { return either_bool(_value > 10); });

  CHECK(
      fcppt::monad::bind(either_int(std::string("test")), bind_function) ==
      either_bool{std::string{"test"}});

  CHECK(fcppt::monad::bind(either_int(20), bind_function) == either_bool(true));

  CHECK(fcppt::monad::bind(either_int(20), [](int) {
          return either_bool(std::string("failure"));
        }) == either_bool(std::string("failure")));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
