//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/variant/exception.hpp>
#include <fcppt/variant/invalid_get.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::variant::invalid_get::invalid_get(
	fcppt::string &&_error
)
:
	fcppt::variant::exception{
		std::move(
			_error
		)
	}
{
}

fcppt::variant::invalid_get::invalid_get(
	invalid_get const &
)
= default;

fcppt::variant::invalid_get::invalid_get(
	invalid_get &&
)
noexcept
= default;

fcppt::variant::invalid_get &
fcppt::variant::invalid_get::operator=(
	invalid_get const &
)
= default;

fcppt::variant::invalid_get &
fcppt::variant::invalid_get::operator=(
	invalid_get &&
)
noexcept
= default;

fcppt::variant::invalid_get::~invalid_get() noexcept
= default;
