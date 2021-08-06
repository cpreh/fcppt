//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/catch/record.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object.hpp>

TEST_CASE("record::make", "[record]")
{
  FCPPT_RECORD_MAKE_LABEL(int_label);
  FCPPT_RECORD_MAKE_LABEL(bool_label);

  using my_record = fcppt::record::
      object<fcppt::record::element<int_label, int>, fcppt::record::element<bool_label, bool>>;

  CHECK(
      my_record{int_label{} = 5, bool_label{} = true} ==
      fcppt::record::make(int_label{} = 5, bool_label{} = true));
}
