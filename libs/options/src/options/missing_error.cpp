//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::options::missing_error::missing_error(
	fcppt::options::state &&_state,
	fcppt::string &&_error
)
:
	state_{
		std::move(
			_state
		)
	},
	error_{
		std::move(
			_error
		)
	}
{
}
