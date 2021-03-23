//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/record/are_disjoint.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_impl.hpp>

int main()
{
  FCPPT_RECORD_MAKE_LABEL(int_label);

  FCPPT_RECORD_MAKE_LABEL(bool_label);

  using record1 = fcppt::record::object<fcppt::record::element<int_label, int>>;

  using record2 = fcppt::record::object<fcppt::record::element<bool_label, bool>>;

  using record3 = fcppt::record::
      object<fcppt::record::element<int_label, int>, fcppt::record::element<bool_label, bool>>;

  static_assert(fcppt::record::are_disjoint<record1, record2>::value);

  static_assert(!fcppt::record::are_disjoint<record1, record3>::value);

  static_assert(!fcppt::record::are_disjoint<record2, record3>::value);
}
