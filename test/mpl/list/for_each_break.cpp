//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/loop.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/mpl/list/for_each_break.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

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

class function2
{
public:
  function2() : value_{0} {}

  [[nodiscard]] fcppt::loop operator()(fcppt::tag<int>) const
  {
    value_ += 2;

    return fcppt::loop::continue_;
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

FCPPT_CATCH_BEGIN

TEST_CASE("mpl::for_each_break", "[mpl]")
{
  {
    function1 const func{};

    fcppt::mpl::list::for_each_break<fcppt::mpl::list::object<int, bool>>(func);

    CHECK(func.value() == 2);
  }

  {
    function2 const func{};

    fcppt::mpl::list::for_each_break<fcppt::mpl::list::object<int, bool>>(func);

    CHECK(func.value() == 3);
  }
}

FCPPT_CATCH_END
