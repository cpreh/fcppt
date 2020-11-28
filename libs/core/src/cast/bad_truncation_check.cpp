//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/from_std_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/type_name_from_index.hpp>
#include <fcppt/cast/bad_truncation_check.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeindex>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::cast::bad_truncation_check::bad_truncation_check(
    fcppt::string &&_source_value,
    std::type_index const &_source,
    std::type_index const &_destination)
    : fcppt::exception(
          FCPPT_TEXT("Invalid truncation_check_cast from ") + std::move(_source_value) +
          FCPPT_TEXT(" of type \"") + fcppt::from_std_string(fcppt::type_name_from_index(_source)) +
          FCPPT_TEXT("\" to type \"") +
          fcppt::from_std_string(fcppt::type_name_from_index(_destination)) + FCPPT_TEXT('"')),
      source_(_source),
      destination_(_destination)
{
}

// NOLINTNEXTLINE(cppcoreguidelines-pro-type-member-init,hicpp-member-init)
fcppt::cast::bad_truncation_check::bad_truncation_check(bad_truncation_check const &) = default;

// NOLINTNEXTLINE(cppcoreguidelines-pro-type-member-init,hicpp-member-init)
fcppt::cast::bad_truncation_check::bad_truncation_check(bad_truncation_check &&) noexcept = default;

fcppt::cast::bad_truncation_check &
fcppt::cast::bad_truncation_check::operator=(bad_truncation_check const &) = default;

fcppt::cast::bad_truncation_check &
fcppt::cast::bad_truncation_check::operator=(bad_truncation_check &&) noexcept = default;

fcppt::cast::bad_truncation_check::~bad_truncation_check() noexcept = default;

std::type_index const &fcppt::cast::bad_truncation_check::source() const { return this->source_; }

std::type_index const &fcppt::cast::bad_truncation_check::destination() const
{
  return this->destination_;
}
