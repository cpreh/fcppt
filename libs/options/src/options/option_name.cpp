//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/options/option_name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::options::option_name::option_name(
	fcppt::string &&_name,
	is_short const _is_short
)
:
	name_{
		std::move(
			_name
		)
	},
	is_short_{
		_is_short
	}
{
}
