//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_FLAG_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_FLAG_IMPL_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/options/exception.hpp>
#include <fcppt/options/flag_decl.hpp>
#include <fcppt/options/flag_name.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_error.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value.hpp>
#include <fcppt/options/detail/check_short_long_names.hpp>
#include <fcppt/options/detail/flag_is_short.hpp>
#include <fcppt/options/detail/help_text.hpp>
#include <fcppt/options/detail/long_or_short_name.hpp>
#include <fcppt/options/detail/use_flag.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Label, typename Type>
fcppt::options::flag<Label, Type>::flag(
    fcppt::options::optional_short_name &&_short_name,
    fcppt::options::long_name &&_long_name,
    active_value &&_active_value,
    inactive_value &&_inactive_value,
    fcppt::options::optional_help_text &&_help_text)
    : short_name_{std::move(_short_name)},
      long_name_(std::move(_long_name)),
      active_value_{std::move(_active_value)},
      inactive_value_{std::move(_inactive_value)},
      help_text_(std::move(_help_text))
{
  fcppt::options::detail::check_short_long_names(this->short_name_, this->long_name_);

  if (_active_value.get() == _inactive_value.get())
  {
    throw fcppt::options::exception{
        FCPPT_TEXT("The active and the inactive value must be different: ") +
        fcppt::output_to_fcppt_string(_active_value.get())};
  }
}

template <typename Label, typename Type>
fcppt::options::parse_result<typename fcppt::options::flag<Label, Type>::result_type>
fcppt::options::flag<Label, Type>::parse(
    fcppt::options::state &&_state, fcppt::options::parse_context const &) const
{
  bool const long_found{fcppt::options::detail::use_flag(
      fcppt::make_ref(_state),
      this->long_name_.get(),
      fcppt::options::detail::flag_is_short{false})};

  auto const make_success(
      [&_state, this](bool const _value) -> fcppt::options::parse_result<result_type> {
        return fcppt::options::parse_result<result_type>{
            fcppt::options::state_with_value<result_type>{
                std::move(_state),
                result_type{
                    Label{} = _value ? this->active_value_.get() : this->inactive_value_.get()}}};
      });

  return fcppt::optional::maybe(
      short_name_,
      [make_success, long_found] { return make_success(long_found); },
      [this, make_success, long_found, &_state](fcppt::options::short_name const &_short_name) {
        bool const short_found{fcppt::options::detail::use_flag(
            fcppt::make_ref(_state),
            _short_name.get(),
            fcppt::options::detail::flag_is_short{true})};

        return long_found && short_found
                   ? fcppt::either::make_failure<fcppt::options::state_with_value<result_type>>(
                         fcppt::options::parse_error{fcppt::options::other_error{
                             FCPPT_TEXT("Both the short flag name ") + _short_name.get() +
                             FCPPT_TEXT(" and the long flag name ") + this->long_name_.get() +
                             FCPPT_TEXT(" were specified at the same time")}})
                   : make_success(short_found || long_found);
      });
}

template <typename Label, typename Type>
fcppt::options::flag_name_set fcppt::options::flag<Label, Type>::flag_names() const
{
  fcppt::options::flag_name_set result{fcppt::options::flag_name{this->long_name_.get()}};

  fcppt::optional::maybe_void(
      this->short_name_, [&result](fcppt::options::short_name const &_short_name) {
        result.insert(fcppt::options::flag_name{_short_name.get()});
      });

  return result;
}

template <typename Label, typename Type>
fcppt::options::option_name_set fcppt::options::flag<Label, Type>::option_names() const
{
  return fcppt::options::option_name_set{};
}

template <typename Label, typename Type>
fcppt::string fcppt::options::flag<Label, Type>::usage() const
{
  return FCPPT_TEXT("[ ") +
         fcppt::options::detail::long_or_short_name(this->long_name_, this->short_name_) +
         FCPPT_TEXT(" ]") + fcppt::options::detail::help_text(this->help_text_);
}

template <typename Label, typename Type>
fcppt::options::optional_short_name const &fcppt::options::flag<Label, Type>::short_name() const
{
  return this->short_name_;
}

template <typename Label, typename Type>
fcppt::options::long_name const &fcppt::options::flag<Label, Type>::long_name() const
{
  return this->long_name_;
}

#endif
