//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/assert/exception.hpp>
#include <fcppt/assert/information.hpp>
#include <fcppt/assert/make_message.hpp>


fcppt::assert_::exception::exception(
	fcppt::assert_::information const &_information
)
:
	fcppt::exception(
		fcppt::assert_::make_message(
			_information
		)
	),
	information_(
		_information
	)
{
}

fcppt::assert_::exception::exception(
	exception const &
)
= default;

fcppt::assert_::exception::exception(
	exception &&
)
noexcept
= default;

fcppt::assert_::exception &
fcppt::assert_::exception::operator=(
	exception const &
)
= default;

fcppt::assert_::exception &
fcppt::assert_::exception::operator=(
	exception &&
)
noexcept
= default;

fcppt::assert_::exception::~exception() noexcept
=
default;

fcppt::assert_::information const &
fcppt::assert_::exception::information() const
{
	return
		this->information_;
}
