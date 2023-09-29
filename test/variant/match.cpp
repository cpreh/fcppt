//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("variant::match", "[variant]")
{
  using variant = fcppt::variant::object<int, std::string>;

  std::string const result(fcppt::variant::match(
      variant(42),
      [](int const _value) { return std::to_string(_value); },
      [](std::string const &_value) { return _value; }));

  CHECK(result == "42");
}

TEST_CASE("variant::match move", "[variant]")
{
  using int_unique_ptr = fcppt::unique_ptr<int>;

  using variant = fcppt::variant::object<int_unique_ptr, std::string>;

  std::string const result(fcppt::variant::match(
      variant(fcppt::make_unique_ptr<int>(42)),
      [](int_unique_ptr &&_value) { return std::to_string(*_value); }, // NOLINT(cppcoreguidelines-rvalue-reference-param-not-moved)
      [](std::string const &_value) { return _value; }));

  CHECK(result == "42");
}

namespace
{
int test_func(int const _x) { return _x; }
}

TEST_CASE("variant::match free function", "[variant]")
{
  using variant = fcppt::variant::object<int>;
  CHECK(fcppt::variant::match(variant{5},&test_func) == 5);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
