//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <exception>
#include <stdexcept>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN

TEST_CASE("optional::to_exception", "[optional]")
{
  using optional_int = fcppt::optional::object<int>;

  auto const make_exception([] { return std::runtime_error{"Invalid"}; });

  CHECK(fcppt::optional::to_exception(optional_int(3), make_exception) == 3);

  CHECK_THROWS_AS(fcppt::optional::to_exception(optional_int(), make_exception), std::exception);
}

FCPPT_CATCH_END
