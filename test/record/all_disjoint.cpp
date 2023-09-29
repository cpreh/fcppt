//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/list/object.hpp>
#include <fcppt/record/all_disjoint.hpp>
#include <fcppt/record/all_disjoint_v.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object_impl.hpp>

int main()
{
  FCPPT_RECORD_MAKE_LABEL(label_1);

  FCPPT_RECORD_MAKE_LABEL(label_2);

  FCPPT_RECORD_MAKE_LABEL(label_3);

  using element_1 = fcppt::record::element<label_1, int>;

  using element_2 = fcppt::record::element<label_2, int>;

  using element_3 = fcppt::record::element<label_3, int>;

  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(fcppt::record::all_disjoint<fcppt::mpl::list::object<
                    fcppt::record::object<element_1>,
                    fcppt::record::object<element_2>,
                    fcppt::record::object<element_3>>>::value);

  // NOLINTNEXTLINE(modernize-type-traits)
  static_assert(!fcppt::record::all_disjoint<fcppt::mpl::list::object<
                    fcppt::record::object<element_1>,
                    fcppt::record::object<element_1, element_2>,
                    fcppt::record::object<element_3>>>::value);

  static_assert(fcppt::record::all_disjoint_v<fcppt::mpl::list::object<
                    fcppt::record::object<element_1>,
                    fcppt::record::object<element_2>,
                    fcppt::record::object<element_3>>>);

  static_assert(!fcppt::record::all_disjoint_v<fcppt::mpl::list::object<
                    fcppt::record::object<element_1>,
                    fcppt::record::object<element_1, element_2>,
                    fcppt::record::object<element_3>>>);

}
