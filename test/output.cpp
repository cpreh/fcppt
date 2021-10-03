//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/output.hpp>
#include <fcppt/output_pair.hpp>
#include <fcppt/output_range.hpp>
#include <fcppt/output_string.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

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

FCPPT_CATCH_END
