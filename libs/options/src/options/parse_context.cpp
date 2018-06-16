//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::options::parse_context::parse_context(
	fcppt::options::option_name_set &&_option_names
)
:
	option_names_{
		std::move(
			_option_names
		)
	}
{
}
