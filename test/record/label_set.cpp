//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/metal/set/contains.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/label_set.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_impl.hpp>

int main()
{
  FCPPT_RECORD_MAKE_LABEL(int_label);

  FCPPT_RECORD_MAKE_LABEL(bool_label);

  using my_record = fcppt::record::
      object<fcppt::record::element<int_label, int>, fcppt::record::element<bool_label, bool>>;

  using label_set = fcppt::record::label_set<my_record>;

  static_assert(fcppt::metal::set::contains<label_set, int_label>::value);

  static_assert(fcppt::metal::set::contains<label_set, bool_label>::value);

  static_assert(!fcppt::metal::set::contains<label_set, int>::value);
}
