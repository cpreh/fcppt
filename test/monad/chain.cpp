//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/extract_from_string.hpp>
#include <fcppt/monad/chain.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/monad.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("monad::chain", "[monad]")
{
  CHECK(fcppt::monad::chain(fcppt::optional::make(std::string{"1"}), [](std::string const &_value) {
          return fcppt::extract_from_string<int>(_value);
        }) == fcppt::optional::make(1));
}
