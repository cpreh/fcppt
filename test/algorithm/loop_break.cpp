//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/loop.hpp>
#include <fcppt/algorithm/loop_break.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/algorithm/loop_break_tuple.hpp>
#include <fcppt/mpl/list/object.hpp>
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

namespace
{
class function1
{
public:
  function1() : value_{0} {}

  [[nodiscard]] fcppt::loop operator()(fcppt::tag<int>) const
  {
    value_ += 2;

    return fcppt::loop::break_;
  }

  [[nodiscard]] fcppt::loop operator()(fcppt::tag<bool>) const
  {
    ++value_;

    return fcppt::loop::continue_;
  }

  [[nodiscard]] int value() const { return value_; }

private:
  mutable int value_;
};

}

TEST_CASE("algorithm_loop_break mpl"
          "[algorithm_loop_break]")
{
  function1 const func{};

  fcppt::algorithm::loop_break(fcppt::mpl::list::object<int, bool>{}, func);

  CHECK(func.value() == 2);
}
