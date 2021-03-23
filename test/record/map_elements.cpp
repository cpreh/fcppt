//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/map_elements.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
template <typename Function, typename Param>
using result_helper = std::result_of_t<Function(fcppt::record::element_to_type<Param>)>;

}

int main()
{
  FCPPT_RECORD_MAKE_LABEL(int_label);

  FCPPT_RECORD_MAKE_LABEL(bool_label);

  using my_record = fcppt::record::
      object<fcppt::record::element<int_label, int>, fcppt::record::element<bool_label, bool>>;

  using result1 = fcppt::record::map_elements<
      my_record,
      metal::bind<
          ::metal::lambda<fcppt::optional::object>,
          metal::bind<metal::lambda<fcppt::record::element_to_type>, metal::_1>>>;

  auto const transform([](auto const &_value) { return fcppt::optional::make(_value); });

  using result2 = fcppt::record::map_elements<
      my_record,
      metal::bind<metal::lambda<result_helper>, metal::always<decltype(transform)>, metal::_1>>;

  static_assert(
      std::is_same_v<
          fcppt::record::label_value_type<result1, int_label>,
          fcppt::optional::object<int>>,
      "Invalid int label in result1");

  static_assert(
      std::is_same_v<
          fcppt::record::label_value_type<result1, bool_label>,
          fcppt::optional::object<bool>>,
      "Invalid bool label in result1");

  static_assert(
      std::is_same_v<
          fcppt::record::label_value_type<result2, int_label>,
          fcppt::optional::object<int>>,
      "Invalid int label in result2");

  static_assert(
      std::is_same_v<
          fcppt::record::label_value_type<result2, bool_label>,
          fcppt::optional::object<bool>>,
      "Invalid bool label in result2");
}
