//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/unit_fwd.hpp>
#include <fcppt/monad/bind.hpp>
#include <fcppt/monad/constructor.hpp>
#include <fcppt/monad/inner_type.hpp>
#include <fcppt/monad/return.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/monad.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
static_assert(std::is_same_v<
              fcppt::monad::constructor<fcppt::optional::object<fcppt::unit>, int>,
              fcppt::optional::object<int>>);

static_assert(std::is_same_v<fcppt::monad::inner_type<fcppt::optional::object<int>>, int>);

}

TEST_CASE("optional monad return", "[optional]")
{
  CHECK(fcppt::monad::return_<fcppt::optional::object<fcppt::unit>>(5) == fcppt::optional::make(5));
}

TEST_CASE("optional monad bind", "[optional]")
{
  using optional_string = fcppt::optional::object<std::string>;

  CHECK(fcppt::monad::bind(optional_string{"test2"}, [](std::string const &_value) {
          return optional_string{"test1" + _value};
        }) == optional_string{"test1test2"});

  CHECK(fcppt::monad::bind(optional_string{"test2"}, [](std::string const &) {
          return optional_string{};
        }) == optional_string{});
}
