//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/format.hpp>
#include <fcppt/string.hpp>
#include <fcppt/log/format/inserter.hpp>


fcppt::string
fcppt::log::format::inserter(
	fcppt::string const &_format_string,
	fcppt::string const &_text
)
{
	return
		(
			fcppt::format(
				_format_string
			)
			% _text
		).str();
}
