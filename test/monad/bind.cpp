//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/extract_from_string.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/monad/bind.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/monad.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("monad::bind", "[monad]")
{
  CHECK(fcppt::monad::bind(fcppt::optional::make(std::string{"1"}), [](std::string const &_value) {
          return fcppt::extract_from_string<int>(_value);
        }) == fcppt::optional::make(1));
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
