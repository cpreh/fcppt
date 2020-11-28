//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/options/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::exception::exception(fcppt::string &&_string)
    : fcppt::exception{FCPPT_TEXT("fcppt::options: ") + std::move(_string)}
{
}

fcppt::options::exception::exception(exception const &) = default;

fcppt::options::exception::exception(exception &&) noexcept = default;

fcppt::options::exception &fcppt::options::exception::operator=(exception const &) = default;

fcppt::options::exception &fcppt::options::exception::operator=(exception &&) noexcept = default;

fcppt::options::exception::~exception() noexcept = default;
