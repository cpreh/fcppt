//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/loop.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/algorithm/loop_break.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/algorithm/loop_break_record.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/algorithm/loop_break_tuple.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

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
  mutable int value_; // NOLINT(cppcoreguidelines-use-default-member-init,modernize-use-default-member-init)
};

}

TEST_CASE("algorithm_loop_break mpl"
          "[algorithm_loop_break]")
{
  function1 const func{};

  fcppt::algorithm::loop_break(fcppt::mpl::list::object<int, bool>{}, func);

  CHECK(func.value() == 2);
}

namespace
{
class function2
{
public:
  function2() : value_{0} {}

  [[nodiscard]] fcppt::loop operator()(int) const
  {
    value_ += 2;

    return fcppt::loop::break_;
  }

  [[nodiscard]] fcppt::loop operator()(bool) const
  {
    ++value_;

    return fcppt::loop::continue_;
  }

  [[nodiscard]] int value() const { return value_; }
private:
  mutable int value_; // NOLINT(cppcoreguidelines-use-default-member-init,modernize-use-default-member-init)
};

}

TEST_CASE("algorithm_loop_break record"
          "[algorithm_loop_break]")
{
  FCPPT_RECORD_MAKE_LABEL(label1);
  FCPPT_RECORD_MAKE_LABEL(label2);

  using record = fcppt::record::
      object<fcppt::record::element<label1, int>, fcppt::record::element<label2, bool>>;

  function2 const func{};

  fcppt::algorithm::loop_break(record{label1{} = 10, label2{} = false}, func);

  CHECK(func.value() == 2);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
