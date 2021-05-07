//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/detail/contains_initializer.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
FCPPT_RECORD_MAKE_LABEL(int_label);

FCPPT_RECORD_MAKE_LABEL(bool_label);

FCPPT_RECORD_MAKE_LABEL(float_label);

using int_element = fcppt::record::element<int_label, int>;

using bool_element = fcppt::record::element<bool_label, bool>;

using float_element = fcppt::record::element<float_label, float>;

template <typename... Args>
void test(Args &&...)
{
  using args_type = metal::list<std::remove_cvref_t<Args>...>;

  static_assert(
      fcppt::record::detail::contains_initializer<args_type, int_element>::value,
      "Does not contain int element");

  static_assert(
      fcppt::record::detail::contains_initializer<args_type, bool_element>::value,
      "Does not contain bool element");

  static_assert(
      !fcppt::record::detail::contains_initializer<args_type, float_element>::value,
      "Does contain float element");
}

}

int main() { test(bool_label{} = false, int_label{} = 0); }
