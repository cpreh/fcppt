//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/location_string_vector.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("log::location", "[log]")
{
  CHECK(fcppt::log::location{}.string().empty());

  CHECK(
      fcppt::log::location{fcppt::log::name{FCPPT_TEXT("root")}}.string() ==
      fcppt::string{FCPPT_TEXT("root")});

  CHECK(
      fcppt::log::location{
          fcppt::log::location_string_vector{FCPPT_TEXT("root"), FCPPT_TEXT("child")}}
          .string() == fcppt::string{FCPPT_TEXT("root::child")});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
