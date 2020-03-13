//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/name.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/format/optional_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::log::parameters::parameters(
	fcppt::log::name _name,
	fcppt::log::format::optional_function &&_formatter
)
:
	name_{
		std::move(
			_name
		)
	},
	formatter_{
		std::move(
			_formatter
		)
	}
{
}

fcppt::log::name const &
fcppt::log::parameters::name() const
{
	return
		this->name_;
}

fcppt::log::format::optional_function const &
fcppt::log::parameters::formatter() const
{
	return
		this->formatter_;
}
