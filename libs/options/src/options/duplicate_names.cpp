//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/options/duplicate_names.hpp>
#include <fcppt/options/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::options::duplicate_names::duplicate_names(
	fcppt::string &&_string
)
:
	fcppt::options::exception{
		std::move(
			_string
		)
	}
{
}

fcppt::options::duplicate_names::duplicate_names(
	duplicate_names const &
)
= default;

fcppt::options::duplicate_names::duplicate_names(
	duplicate_names &&
)
noexcept
= default;

fcppt::options::duplicate_names &
fcppt::options::duplicate_names::operator=(
	duplicate_names const &
)
= default;

fcppt::options::duplicate_names &
fcppt::options::duplicate_names::operator=(
	duplicate_names &&
)
noexcept
= default;

fcppt::options::duplicate_names::~duplicate_names() noexcept
= default;
