//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/record/comparison.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/init.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{
FCPPT_RECORD_MAKE_LABEL(int_label);

template <typename Record>
struct init_function
{
  template <typename Type>
  fcppt::record::label_value_type<Record, int_label>
  operator()(fcppt::record::element<int_label, Type>) const
  {
    return 1;
  }
};

template <typename Record>
void init_test()
{
  auto const record(fcppt::record::init<Record>(init_function<Record>{}));

  CHECK(fcppt::record::get<int_label>(record) == 1);

  CHECK(Record{int_label{} = 1} == record);
}

}

TEST_CASE("record::init", "[record]")
{
  using my_record = fcppt::record::object<fcppt::record::element<int_label, int>>;

  init_test<my_record>();
}
