//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string_to_wstring_conversion_failed.hpp>
#include <fcppt/strong_typedef_impl.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <stdexcept>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

// NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
fcppt::string_to_wstring_conversion_failed::string_to_wstring_conversion_failed(input_type &&_input)
    : std::runtime_error{
          "Failed to convert std::string to std::wstring: \"" + _input.get() + "\"!"},
      input_{std::move(_input.get())}
{
}

fcppt::string_to_wstring_conversion_failed::string_to_wstring_conversion_failed(
    string_to_wstring_conversion_failed const &) = default;

fcppt::string_to_wstring_conversion_failed::string_to_wstring_conversion_failed(
    string_to_wstring_conversion_failed &&) noexcept = default;

fcppt::string_to_wstring_conversion_failed &fcppt::string_to_wstring_conversion_failed::operator=(
    string_to_wstring_conversion_failed const &) = default;

fcppt::string_to_wstring_conversion_failed &fcppt::string_to_wstring_conversion_failed::operator=(
    string_to_wstring_conversion_failed &&) noexcept = default;

fcppt::string_to_wstring_conversion_failed::~string_to_wstring_conversion_failed() noexcept =
    default;

std::string const &fcppt::string_to_wstring_conversion_failed::input() const
{
  return this->input_;
}
