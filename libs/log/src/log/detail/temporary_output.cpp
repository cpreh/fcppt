//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string.hpp>
#include <fcppt/log/detail/temporary_output.hpp>

fcppt::log::detail::temporary_output::temporary_output() : stream_{} {}

fcppt::log::detail::temporary_output::temporary_output(
    fcppt::log::detail::temporary_output &&) noexcept(false) = default;

fcppt::log::detail::temporary_output &fcppt::log::detail::temporary_output::operator=(
    fcppt::log::detail::temporary_output &&) noexcept(false) = default;

fcppt::log::detail::temporary_output::~temporary_output() = default;

fcppt::string fcppt::log::detail::temporary_output::result() const { return this->stream_.str(); }
