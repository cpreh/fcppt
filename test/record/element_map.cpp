//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/map/at.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_map.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_impl.hpp>

int main()
{
  FCPPT_RECORD_MAKE_LABEL(int_label);

  FCPPT_RECORD_MAKE_LABEL(bool_label);

  using my_record = fcppt::record::
      object<fcppt::record::element<int_label, int>, fcppt::record::element<bool_label, bool>>;

  using element_map = fcppt::record::element_map<my_record>;

  static_assert(std::is_same_v<fcppt::mpl::map::at<element_map, int_label>, int>);

  static_assert(std::is_same_v<fcppt::mpl::map::at<element_map, bool_label>, bool>);
}
