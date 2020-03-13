//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>


fcppt::exception::exception(
	fcppt::string &&_string
)
:
	string_(
		std::move(
			_string
		)
	)
{
}

fcppt::exception::exception(
	exception const &
)
= default;

fcppt::exception::exception(
	exception &&
)
noexcept
= default;

fcppt::exception &
fcppt::exception::operator=(
	exception const &
)
= default;

fcppt::exception &
fcppt::exception::operator=(
	exception &&
)
noexcept
= default;

fcppt::string const &
fcppt::exception::string() const
{
	return
		this->string_;
}

char const *
fcppt::exception::what() const noexcept
{
	return
		"what cannot be supplied by an fcppt::exception, do not catch fcppt::exception as std::exception";
}

fcppt::exception::~exception() noexcept
= default;
