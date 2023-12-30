//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_OPTIONAL_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTIONAL_IMPL_HPP_INCLUDED

#include <fcppt/make_recursive.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/nothing.hpp>
#include <fcppt/optional/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/options/deref.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/optional_decl.hpp> // IWYU pragma: export
#include <fcppt/options/optional_usage.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_error.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value.hpp>
#include <fcppt/options/usage.hpp>
#include <fcppt/options/usage_variant.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/init.hpp>
#include <fcppt/record/map.hpp>
#include <fcppt/record/permute.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Parser>
fcppt::options::optional<Parser>::optional(Parser &&_parser) : parser_{std::move(_parser)}
{
}

template <typename Parser>
fcppt::options::parse_result<typename fcppt::options::optional<Parser>::result_type>
fcppt::options::optional<Parser>::parse(
    // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
    fcppt::options::state &&_state, fcppt::options::parse_context const &_context) const
{
  return fcppt::either::match(
      fcppt::options::deref(this->parser_).parse(fcppt::options::state{_state}, _context),
      [](fcppt::options::parse_error &&_error) {
        FCPPT_PP_PUSH_WARNING
        FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)

        return fcppt::variant::match(
            std::move(_error),
            // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
            [](fcppt::options::missing_error &&_missing_error)
            {
              return fcppt::options::parse_result<result_type>{
                  fcppt::options::state_with_value<result_type>{
                      std::move(_missing_error.state()),
                      fcppt::record::init<result_type>(
                          []<typename L, typename T>(fcppt::record::element<L, T>)
                          { return fcppt::optional::nothing{}; })}};
            },
            [](fcppt::options::error &&_other_error)
            {
              return fcppt::either::make_failure<fcppt::options::state_with_value<result_type>>(
                  fcppt::options::parse_error{std::move(_other_error)});
            });

        FCPPT_PP_POP_WARNING
      },
      // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
      [](fcppt::options::state_with_value<fcppt::options::result_of<Parser>> &&_result) {
        return fcppt::options::parse_result<result_type>{
            fcppt::options::state_with_value<result_type>{
                std::move(_result.state()),
                fcppt::record::permute<result_type>(
                    fcppt::record::map(std::move(_result.value()), [](auto &&_element) {
                      return fcppt::optional::make(std::forward<decltype(_element)>(_element));
                    }))}};
      });
}

template <typename Parser>
fcppt::options::flag_name_set fcppt::options::optional<Parser>::flag_names() const
{
  return fcppt::options::deref(this->parser_).flag_names();
}

template <typename Parser>
fcppt::options::option_name_set fcppt::options::optional<Parser>::option_names() const
{
  return fcppt::options::deref(this->parser_).option_names();
}

template <typename Parser>
fcppt::options::usage fcppt::options::optional<Parser>::usage() const
{
  return fcppt::options::usage{fcppt::options::usage_variant{fcppt::options::optional_usage{
      fcppt::make_recursive(fcppt::options::deref(this->parser_).usage())}}};
}

#endif
