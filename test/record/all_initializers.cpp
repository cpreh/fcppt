//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/list/object.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/detail/all_initializers.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
FCPPT_RECORD_MAKE_LABEL(int_label);

FCPPT_RECORD_MAKE_LABEL(bool_label);

using int_element = fcppt::record::element<int_label, int>;

using bool_element = fcppt::record::element<bool_label, bool>;

template <bool Expected, typename... Args>
void test(Args &&...)
{
  using elements = fcppt::mpl::list::object<bool_element, int_element>;

  using args_type = fcppt::mpl::list::object<std::remove_cvref_t<Args>...>;

  static_assert(
      fcppt::record::detail::all_initializers<elements, args_type>::value == Expected,
      "Broken all_initializers");
}

}

int main()
{
  test<true>(bool_label{} = false, int_label{} = 0);

  test<false>(bool_label{} = false);

  test<false>(int_label{} = 0);

  test<false>();
}
