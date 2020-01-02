//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::options::state::state(
	fcppt::args_vector &&_args
)
:
	args_{
		std::move(
			_args
		)
	}
{
}

bool
fcppt::options::state::empty() const
{
	return
		args_.empty();
}
