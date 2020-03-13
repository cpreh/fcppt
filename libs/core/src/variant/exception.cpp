//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/variant/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::variant::exception::exception(
	fcppt::string &&_string
)
:
	fcppt::exception{
		FCPPT_TEXT("variant: ")
		+
		std::move(
			_string
		)
	}
{
}

fcppt::variant::exception::exception(
	exception const &
)
= default;

fcppt::variant::exception::exception(
	exception &&
)
noexcept
= default;

fcppt::variant::exception &
fcppt::variant::exception::operator=(
	exception const &
)
= default;

fcppt::variant::exception &
fcppt::variant::exception::operator=(
	exception &&
)
noexcept
= default;

fcppt::variant::exception::~exception() noexcept
= default;
