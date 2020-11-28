//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/time/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::time::exception::exception(fcppt::string &&_what)
    : fcppt::exception{FCPPT_TEXT("time: ") + std::move(_what)}
{
}

fcppt::time::exception::exception(exception const &) = default;

fcppt::time::exception::exception(exception &&) noexcept = default;

fcppt::time::exception &fcppt::time::exception::operator=(exception const &) = default;

fcppt::time::exception &fcppt::time::exception::operator=(exception &&) noexcept = default;

fcppt::time::exception::~exception() noexcept = default;
