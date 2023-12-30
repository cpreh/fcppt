//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_ARGUMENT_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_ARGUMENT_IMPL_HPP_INCLUDED

#include <fcppt/extract_from_string.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/string.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/options/argument_conversion_error.hpp>
#include <fcppt/options/argument_decl.hpp> // IWYU pragma: export
#include <fcppt/options/argument_usage.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/error_variant.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/missing_argument_error.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/missing_error_variant.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_error.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/pretty_type.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/options/detail/pop_arg.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element.hpp> // IWYU pragma: keep
#include <fcppt/record/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Label, typename Type>
fcppt::options::argument<Label, Type>::argument(
    fcppt::options::long_name &&_long_name, fcppt::options::optional_help_text &&_help_text)
    : long_name_{std::move(_long_name)}, help_text_{std::move(_help_text)}
{
}

template <typename Label, typename Type>
fcppt::options::parse_result<typename fcppt::options::argument<Label, Type>::result_type>
fcppt::options::argument<Label, Type>::parse(
    fcppt::options::state &&_state, fcppt::options::parse_context const &_context) const
{
  return fcppt::either::bind(
      fcppt::either::from_optional(
          fcppt::options::detail::pop_arg(fcppt::make_ref(_state), _context),
          [&_state, this]
          {
            return fcppt::options::parse_error{fcppt::options::missing_error{
                std::move(_state),
                fcppt::options::missing_error_variant{
                    fcppt::options::missing_argument_error{this->long_name_}}}};
          }),
      [&_state, this](fcppt::string const &_arg)
      {
        FCPPT_PP_PUSH_WARNING
        FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)

        return fcppt::either::from_optional(
            fcppt::optional::map(
                fcppt::extract_from_string<Type>(_arg),
                [&_state](Type &&_value)
                {
                  return fcppt::options::state_with_value<result_type>{
                      std::move(_state), result_type{Label{} = std::move(_value)}};
                }),
            [this, &_arg]
            {
              return fcppt::options::parse_error{fcppt::options::error{
                  fcppt::options::error_variant{fcppt::options::argument_conversion_error{
                      _arg, fcppt::options::pretty_type<Type>(), this->long_name_}}}};
            });

        FCPPT_PP_POP_WARNING
      });
}

template <typename Label, typename Type>
fcppt::options::flag_name_set fcppt::options::argument<Label, Type>::flag_names() const
{
  return fcppt::options::flag_name_set{};
}

template <typename Label, typename Type>
fcppt::options::option_name_set fcppt::options::argument<Label, Type>::option_names() const
{
  return fcppt::options::option_name_set{};
}

template <typename Label, typename Type>
fcppt::options::usage fcppt::options::argument<Label, Type>::usage() const
{
  return fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::argument_usage{
      this->long_name_, fcppt::options::pretty_type<Type>(), this->help_text_}}};
}

#endif
