//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/options/default_help_switch.hpp>
#include <fcppt/options/help_switch.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>


fcppt::options::help_switch
fcppt::options::default_help_switch()
{
	return
		fcppt::options::help_switch{
			fcppt::options::optional_short_name{},
			fcppt::options::long_name{
				FCPPT_TEXT("help")
			},
			fcppt::options::optional_help_text{}
		};
}
