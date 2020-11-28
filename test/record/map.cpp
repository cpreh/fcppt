//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/make_movable.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/map.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/record/permute.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

TEST_CASE("record::map", "[record]")
{
  FCPPT_RECORD_MAKE_LABEL(int_label);

  FCPPT_RECORD_MAKE_LABEL(move_only_label);

  using result_type = fcppt::record::object<
      fcppt::record::element<int_label, fcppt::optional::object<int>>,
      fcppt::record::
          element<move_only_label, fcppt::optional::object<fcppt::catch_::movable<int>>>>;

  CHECK(
      fcppt::record::permute<result_type>(fcppt::record::map(
          fcppt::record::object<
              fcppt::record::element<int_label, int>,
              fcppt::record::element<move_only_label, fcppt::catch_::movable<int>>>{
              int_label{} = 42, move_only_label{} = fcppt::catch_::make_movable(100)},
          [](auto &&_value) {
            return fcppt::optional::make(std::forward<decltype(_value)>(_value));
          })) == result_type{
                     int_label{} = fcppt::optional::make(42),
                     move_only_label{} = fcppt::optional::make(fcppt::catch_::make_movable(100))});
}
