//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/map_elements.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace
{
template <typename Function, typename Param>
using result_helper = std::invoke_result_t<Function,fcppt::record::element_to_type<Param>>;

}

int main()
{
  FCPPT_RECORD_MAKE_LABEL(int_label);

  FCPPT_RECORD_MAKE_LABEL(bool_label);

  using my_record = fcppt::record::
      object<fcppt::record::element<int_label, int>, fcppt::record::element<bool_label, bool>>;

  using result1 = fcppt::record::map_elements<
      my_record,
      fcppt::mpl::bind<
          fcppt::mpl::lambda<fcppt::optional::object>,
          fcppt::mpl::bind<fcppt::mpl::lambda<fcppt::record::element_to_type>, fcppt::mpl::arg<1>>>>;

  auto const transform([](auto const &_value) { return fcppt::optional::make(_value); });

  using result2 = fcppt::record::map_elements<
      my_record,
      fcppt::mpl::bind<
          fcppt::mpl::lambda<result_helper>,
          fcppt::mpl::constant<decltype(transform)>,
          fcppt::mpl::arg<1>>>;

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
