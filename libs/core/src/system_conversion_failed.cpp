//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/strong_typedef_impl.hpp> // IWYU pragma: keep
#include <fcppt/system_conversion_failed.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

// NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
fcppt::system_conversion_failed::system_conversion_failed(command_type &&_command)
    : fcppt::exception{
          FCPPT_TEXT("Failed to convert command \"") + _command.get() +
          FCPPT_TEXT("\" for fcppt::system!")},
      command_{std::move(_command.get())}
{
}

fcppt::system_conversion_failed::system_conversion_failed(system_conversion_failed const &) =
    default;

fcppt::system_conversion_failed::system_conversion_failed(system_conversion_failed &&) noexcept =
    default;

fcppt::system_conversion_failed &
fcppt::system_conversion_failed::operator=(system_conversion_failed const &) = default;

fcppt::system_conversion_failed &
fcppt::system_conversion_failed::operator=(system_conversion_failed &&) noexcept = default;

fcppt::system_conversion_failed::~system_conversion_failed() noexcept = default;

fcppt::string const &fcppt::system_conversion_failed::command() const { return this->command_; }
