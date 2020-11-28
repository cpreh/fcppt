//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/record/permute.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

TEST_CASE("record::permute", "[record]")
{
  FCPPT_RECORD_MAKE_LABEL(int_label);

  FCPPT_RECORD_MAKE_LABEL(move_label);

  using int_element = fcppt::record::element<int_label, int>;

  using move_element = fcppt::record::element<move_label, fcppt::unique_ptr<int>>;

  using result_record = fcppt::record::object<int_element, move_element>;

  using arg_record = fcppt::record::object<move_element, int_element>;

  result_record const result{fcppt::record::permute<result_record>(
      arg_record{int_label{} = 42, move_label{} = fcppt::make_unique_ptr<int>(100)})};

  CHECK(fcppt::record::get<int_label>(result) == 42);

  CHECK(*fcppt::record::get<move_label>(result) == 100);
}
