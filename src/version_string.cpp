//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/version_string.hpp>
#include <fcppt/lexical_cast.hpp>
#include <fcppt/major_version.hpp>
#include <fcppt/minor_version.hpp>
#include <fcppt/micro_version.hpp>

fcppt::string const
fcppt::version_string()
{
	return
		fcppt::lexical_cast<
			fcppt::string
		>(
			fcppt::major_version::value
		)
		+ FCPPT_TEXT('.')
		+ fcppt::lexical_cast<
			fcppt::string
		>(
			fcppt::minor_version::value
		)
		+ FCPPT_TEXT('.')
		+ fcppt::lexical_cast<
			fcppt::string
		>(
			fcppt::micro_version::value
		);
}
