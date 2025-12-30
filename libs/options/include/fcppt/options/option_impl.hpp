//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_OPTION_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_IMPL_HPP_INCLUDED

#include <fcppt/copy.hpp>
#include <fcppt/extract_from_string.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/strong_typedef_impl.hpp> // IWYU pragma: keep
#include <fcppt/either/apply.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/either/join.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/either/map_failure.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/dual_option_error.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/error_variant.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/missing_error_variant.hpp>
#include <fcppt/options/missing_option_argument_error.hpp>
#include <fcppt/options/missing_option_error.hpp>
#include <fcppt/options/option_conversion_error.hpp>
#include <fcppt/options/option_decl.hpp> // IWYU pragma: export
#include <fcppt/options/option_name.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/option_usage.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_error.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/pretty_type.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/options/detail/flag_is_short.hpp>
#include <fcppt/options/detail/use_option.hpp>
#include <fcppt/options/detail/use_option_result.hpp>
#include <fcppt/options/detail/use_option_success.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element.hpp> // IWYU pragma: keep
#include <fcppt/record/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Label, typename Type>
fcppt::options::option<Label, Type>::option(
    fcppt::options::optional_short_name &&_short_name,
    fcppt::options::long_name &&_long_name,
    optional_default_value &&_default_value,
    fcppt::options::optional_help_text &&_help_text)
    : short_name_(std::move(_short_name)),
      long_name_(std::move(_long_name)),
      default_value_(std::move(_default_value)),
      help_text_{std::move(_help_text)}
{
}

template <typename Label, typename Type>
fcppt::options::parse_result<typename fcppt::options::option<Label, Type>::result_type>
fcppt::options::option<Label, Type>::parse(
    fcppt::options::state &&_state, fcppt::options::parse_context const &) const
{
  using optional_success = fcppt::optional::object<fcppt::options::detail::use_option_success>;
  using flag_result = fcppt::either::object<fcppt::options::parse_error, optional_success>;

  using inner_result = fcppt::either::object<fcppt::options::parse_error, result_type>;

  auto const map_result{
      [](fcppt::options::detail::use_option_result &&_result) -> flag_result
      {
        return fcppt::either::map_failure(
            std::move(_result),
            [](fcppt::options::missing_option_argument_error &&_error)
            {
              return fcppt::options::parse_error{
                  fcppt::options::error{fcppt::options::error_variant{std::move(_error)}}};
            });
      }};

  auto const get_default_value{[&_state, this]() -> inner_result {
    FCPPT_PP_PUSH_WARNING
    FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)

    return fcppt::either::from_optional(
        fcppt::optional::map(
            this->default_value_.get(),
            [](Type const &_value) { return result_type{Label{} = _value}; }),
        [&_state, this]
        {
          return fcppt::options::parse_error{fcppt::options::missing_error{
              std::move(_state),
              fcppt::options::missing_error_variant{
                  fcppt::options::missing_option_error{this->short_name_, this->long_name_}}}};
        });

    FCPPT_PP_POP_WARNING
  }};

  auto const make_value{
      [](fcppt::options::detail::use_option_success const &_success) -> inner_result
      {
        FCPPT_PP_PUSH_WARNING
        FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)

        return fcppt::either::from_optional(
            fcppt::optional::map(
                fcppt::extract_from_string<Type>(_success.value()),
                [](Type &&_value) { return result_type{Label{} = std::move(_value)}; }),
            [&_success]
            {
              return fcppt::options::parse_error{fcppt::options::error{
                  fcppt::options::error_variant{fcppt::options::option_conversion_error{
                      fcppt::copy(_success.value()),
                      fcppt::options::pretty_type<Type>(),
                      fcppt::copy(_success.name())}}}};
            });

        FCPPT_PP_POP_WARNING
      }};

  auto const make_or_default_value{
      [get_default_value, make_value](optional_success const &_opt_value) -> inner_result
      { return fcppt::optional::maybe(_opt_value, get_default_value, make_value); }};

  flag_result const long_found{map_result(fcppt::options::detail::use_option(
      fcppt::make_ref(_state), long_name_.get(), fcppt::options::detail::flag_is_short{false}))};

  auto const combine_results{
      [make_or_default_value, make_value, this](
          fcppt::options::short_name const &_short_name,
          optional_success const &_long_value_opt,
          optional_success const &_short_value_opt) -> inner_result
      {
        FCPPT_PP_PUSH_WARNING
        FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)

        return fcppt::optional::maybe(
            _long_value_opt,
            [&_short_value_opt, make_or_default_value]() -> inner_result
            { return make_or_default_value(_short_value_opt); },
            [make_value, &_short_value_opt, &_short_name, this](
                fcppt::options::detail::use_option_success const &_long_value) -> inner_result
            {
              return _short_value_opt.has_value()
                         ? inner_result{fcppt::options::parse_error{fcppt::options::error{
                               fcppt::options::error_variant{fcppt::options::dual_option_error{
                                   _short_name, this->long_name_}}}}}
                         : make_value(_long_value);
            });

        FCPPT_PP_POP_WARNING
      }};

  return fcppt::either::map(
      fcppt::optional::maybe(
          this->short_name_,
          [make_or_default_value, &long_found]() -> inner_result
          { return fcppt::either::bind(long_found, make_or_default_value); },
          [combine_results, map_result, &long_found, &_state](
              fcppt::options::short_name const &_short_name) -> inner_result
          {
            flag_result const short_found{map_result(fcppt::options::detail::use_option(
                fcppt::make_ref(_state),
                _short_name.get(),
                fcppt::options::detail::flag_is_short{true}))};

            return fcppt::either::join(fcppt::either::apply(
                [&_short_name, combine_results](
                    optional_success const &_result1, optional_success const &_result2)
                { return combine_results(_short_name, _result1, _result2); },
                long_found,
                short_found));
          }),
      [&_state](result_type &&_result) {
        return fcppt::options::state_with_value<result_type>{std::move(_state), std::move(_result)};
      });
}

template <typename Label, typename Type>
fcppt::options::flag_name_set fcppt::options::option<Label, Type>::flag_names() const
{
  return fcppt::options::flag_name_set{};
}

template <typename Label, typename Type>
fcppt::options::option_name_set fcppt::options::option<Label, Type>::option_names() const
{
  fcppt::options::option_name_set result{fcppt::options::option_name{
      fcppt::string{this->long_name_.get()}, fcppt::options::option_name::is_short{false}}};

  fcppt::optional::maybe_void(
      this->short_name_, [&result](fcppt::options::short_name const &_short_name) {
        result.insert(fcppt::options::option_name{
            fcppt::string{_short_name.get()}, fcppt::options::option_name::is_short{true}});
      });

  return result;
}

template <typename Label, typename Type>
fcppt::options::usage fcppt::options::option<Label, Type>::usage() const
{
  return fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::option_usage{
      fcppt::options::option_usage::default_value_type{fcppt::optional::map(
          this->default_value_.get(),
          [](Type const &_value) { return fcppt::output_to_fcppt_string(_value); })},
      this->long_name_,
      this->short_name_,
      fcppt::options::pretty_type<Type>(),
      this->help_text_}}};
}

#endif
