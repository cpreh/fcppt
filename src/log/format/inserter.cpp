//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/format/inserter.hpp>
#include <fcppt/format.hpp>

fcppt::log::format::inserter::inserter(
	string const &_format_string
)
:
	format_string(_format_string)
{}

fcppt::string const
fcppt::log::format::inserter::format(
	string const &dest
) const
{
	return
		(
			fcppt::format(
				format_string
			)
			% dest
		).str();
}
