//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_SUM_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_SUM_IMPL_HPP_INCLUDED

#include <fcppt/copy.hpp>
#include <fcppt/make_recursive.hpp>
#include <fcppt/container/set_union.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/make_left.hpp>
#include <fcppt/options/make_right.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_error.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value.hpp>
#include <fcppt/options/sum_decl.hpp> // IWYU pragma: export
#include <fcppt/options/sum_usage.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/options/detail/combine_errors_sum.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element.hpp> // IWYU pragma: keep
#include <fcppt/record/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/variant/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Label, typename Left, typename Right>
fcppt::options::sum<Label, Left, Right>::sum(Left &&_left, Right &&_right)
    : left_{std::move(_left)}, right_{std::move(_right)}
{
}

template <typename Label, typename Left, typename Right>
fcppt::options::parse_result<typename fcppt::options::sum<Label, Left, Right>::result_type>
fcppt::options::sum<Label, Left, Right>::parse(
    fcppt::options::state &&_state, fcppt::options::parse_context const &_context) const
{
  return fcppt::either::match(
      fcppt::options::deref(this->left_).parse(fcppt::copy(_state), _context),
      [&_context, &_state, this](fcppt::options::parse_error &&_error1)
      {
        FCPPT_PP_PUSH_WARNING
        FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)

        return fcppt::either::match(
            fcppt::options::deref(this->right_).parse(std::move(_state), _context),
            [&_error1](fcppt::options::parse_error &&_error2)
            {
              return fcppt::either::make_failure<fcppt::options::state_with_value<result_type>>(
                  fcppt::options::detail::combine_errors_sum(
                      std::move(_error1), std::move(_error2)));
            },
            // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
            [](fcppt::options::state_with_value<fcppt::options::result_of<Right>> &&_right_result)
            {
              return fcppt::options::parse_result<result_type>{
                  fcppt::options::state_with_value<result_type>{
                      std::move(_right_result.state()),
                      result_type{
                          Label{} = variant{
                              fcppt::options::make_right(std::move(_right_result.value()))}}}};
            });

        FCPPT_PP_POP_WARNING
      },
      // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
      [](fcppt::options::state_with_value<fcppt::options::result_of<Left>> &&_left_result)
      {
        return fcppt::options::parse_result<result_type>{
            fcppt::options::state_with_value<result_type>{
                std::move(_left_result.state()),
                result_type{
                    Label{} =
                        variant{fcppt::options::make_left(std::move(_left_result.value()))}}}};
      });
}

template <typename Label, typename Left, typename Right>
fcppt::options::flag_name_set fcppt::options::sum<Label, Left, Right>::flag_names() const
{
  return fcppt::container::set_union(
      fcppt::options::deref(this->left_).flag_names(),
      fcppt::options::deref(this->right_).flag_names());
}

template <typename Label, typename Left, typename Right>
fcppt::options::option_name_set fcppt::options::sum<Label, Left, Right>::option_names() const
{
  return fcppt::container::set_union(
      fcppt::options::deref(this->left_).option_names(),
      fcppt::options::deref(this->right_).option_names());
}

template <typename Label, typename Left, typename Right>
fcppt::options::usage fcppt::options::sum<Label, Left, Right>::usage() const
{
  return fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::sum_usage{
      fcppt::make_recursive(fcppt::options::deref(this->left_).usage()),
      fcppt::make_recursive(fcppt::options::deref(this->right_).usage())}}};
}

#endif
