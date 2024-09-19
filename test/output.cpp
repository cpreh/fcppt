//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/output.hpp>
#include <fcppt/output_pair.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/output_range.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/output_string.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("output value", "[various]")
{
  std::ostringstream stream{};

  stream << fcppt::output(10);

  CHECK(stream.str() == std::string{"10"});
}

TEST_CASE("output vector", "[various]")
{
  std::ostringstream stream{};

  stream << fcppt::output(std::vector<int>{10, 20});

  CHECK(stream.str() == std::string{"[10,20]"});
}

TEST_CASE("output pair", "[various]")
{
  std::ostringstream stream{};

  stream << fcppt::output(std::make_pair(10, 20));

  CHECK(stream.str() == std::string{"(10,20)"});
}

TEST_CASE("output string", "[various]")
{
  std::ostringstream stream{};

  stream << fcppt::output(std::string{"test"});

  CHECK(stream.str() == std::string{"test"});
}

TEST_CASE("output wide string", "[various]")
{
  std::wostringstream stream{};

  stream << fcppt::output(std::string{"test"});

  CHECK(stream.str() == std::wstring{L"test"});
}

// NOLINTEND(clang-analyzer-optin.core.EnumCastOutOfRange,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
