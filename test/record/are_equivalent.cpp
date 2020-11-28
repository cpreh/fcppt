//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/record/are_equivalent.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_impl.hpp>

int main()
{
  FCPPT_RECORD_MAKE_LABEL(label1);

  FCPPT_RECORD_MAKE_LABEL(label2);

  using record1 = fcppt::record::
      object<fcppt::record::element<label1, int>, fcppt::record::element<label2, bool>>;

  using record2 = fcppt::record::
      object<fcppt::record::element<label2, bool>, fcppt::record::element<label1, int>>;

  static_assert(fcppt::record::are_equivalent<record1, record2>::value);

  using record3 = fcppt::record::
      object<fcppt::record::element<label1, int>, fcppt::record::element<label2, int>>;

  static_assert(!fcppt::record::are_equivalent<record1, record3>::value);

  using record4 = fcppt::record::object<fcppt::record::element<label1, int>>;

  static_assert(!fcppt::record::are_equivalent<record1, record4>::value);
}
