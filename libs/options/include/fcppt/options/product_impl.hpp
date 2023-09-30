//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_PRODUCT_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_PRODUCT_IMPL_HPP_INCLUDED

#include <fcppt/make_recursive.hpp>
#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/container/output.hpp>
#include <fcppt/container/set_intersection.hpp>
#include <fcppt/container/set_union.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/duplicate_names.hpp>
#include <fcppt/options/flag_name.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/product_decl.hpp>
#include <fcppt/options/product_usage.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/multiply_disjoint.hpp>
#include <fcppt/config/external_begin.hpp>
#include <set>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Left, typename Right>
fcppt::options::product<Left, Right>::product(Left &&_left, Right &&_right)
    : left_(std::move(_left)), right_(std::move(_right))
{
  this->check_disjoint();
}

template <typename Left, typename Right>
fcppt::options::parse_result<typename fcppt::options::product<Left, Right>::result_type>
fcppt::options::product<Left, Right>::parse(
    fcppt::options::state &&_state, fcppt::options::parse_context const &_context) const
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)
  return fcppt::either::bind(
      fcppt::options::deref(left_).parse(std::move(_state), _context),
      [&_context,
      // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
       this](fcppt::options::state_with_value<fcppt::options::result_of<Left>> &&_left_result)
          -> fcppt::options::parse_result<result_type> {
        fcppt::options::result_of<Left> &left_value{_left_result.value()};

        return fcppt::either::map(
            fcppt::options::deref(right_).parse(std::move(_left_result.state()), _context),
            [&left_value](fcppt::options::state_with_value<fcppt::options::result_of<Right>>
            // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
                              &&_right_result) {
              return fcppt::options::state_with_value<result_type>{
                  std::move(_right_result.state()),
                  fcppt::record::multiply_disjoint(
                      std::move(left_value), std::move(_right_result.value()))};
            });
      });
  FCPPT_PP_POP_WARNING
}

template <typename Left, typename Right>
fcppt::options::flag_name_set fcppt::options::product<Left, Right>::flag_names() const
{
  return fcppt::container::set_union(
      fcppt::options::deref(left_).flag_names(), fcppt::options::deref(right_).flag_names());
}

template <typename Left, typename Right>
fcppt::options::option_name_set fcppt::options::product<Left, Right>::option_names() const
{
  return fcppt::container::set_union(
      fcppt::options::deref(left_).option_names(), fcppt::options::deref(right_).option_names());
}

template <typename Left, typename Right>
fcppt::options::usage fcppt::options::product<Left, Right>::usage() const
{
  return fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::product_usage{
      fcppt::make_recursive(fcppt::options::deref(this->left_).usage()),
      fcppt::make_recursive(fcppt::options::deref(this->right_).usage())}}};
}

template <typename Left, typename Right>
void fcppt::options::product<Left, Right>::check_disjoint() const
{
  using name_set = std::set<fcppt::string>;

  auto const all_parameters([](auto const &_parser) -> name_set {
    return fcppt::container::set_union(
        fcppt::algorithm::map<name_set>(
            _parser.flag_names(),
            [](fcppt::options::flag_name const &_flag_name) { return _flag_name.get(); }),
        fcppt::algorithm::map<name_set>(
            _parser.option_names(),
            [](fcppt::options::option_name const &_option_name) { return _option_name.name(); }));
  });

  name_set const common_names{fcppt::container::set_intersection(
      all_parameters(fcppt::options::deref(left_)), all_parameters(fcppt::options::deref(right_)))};

  if (!common_names.empty())
  {
    throw fcppt::options::duplicate_names{
        FCPPT_TEXT("The following names appear multiple times in a product parser: ") +
        fcppt::output_to_fcppt_string(fcppt::container::output(common_names))};
  }
}

#endif
