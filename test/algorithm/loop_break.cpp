//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/loop.hpp>
#include <fcppt/algorithm/loop_break.hpp>
#include <fcppt/algorithm/loop_break_tuple.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

TEST_CASE("algorithm_loop_break tuple"
          "[algorithm_loop_break]")
{
  auto const tuple(fcppt::tuple::make(42, 10L));

  std::string result{};

  fcppt::algorithm::loop_break(tuple, [&result](auto const &_value) {
    result += std::to_string(_value);

    return fcppt::loop::continue_;
  });

  CHECK(result == "4210");
}
