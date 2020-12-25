//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/tag.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_tag_tuple.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/tuple/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

int main()
{
  FCPPT_RECORD_MAKE_LABEL(int_label);

  FCPPT_RECORD_MAKE_LABEL(bool_label);

  using int_element = fcppt::record::element<int_label, int>;

  using bool_element = fcppt::record::element<bool_label, bool>;

  using my_record = fcppt::record::object<int_element, bool_element>;

  using tag_tuple = fcppt::record::element_tag_tuple<my_record>;

  static_assert(
      std::is_same_v<tag_tuple, fcppt::tuple::object<fcppt::tag<int_element>, fcppt::tag<bool_element>>>);
}
