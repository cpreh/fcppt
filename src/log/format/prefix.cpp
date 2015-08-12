//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/log/format/inserter.hpp>
#include <fcppt/log/format/prefix.hpp>
#include <fcppt/log/format/function.hpp>


fcppt::log::format::function
fcppt::log::format::prefix(
	fcppt::string const &_prefix
)
{
	return
		fcppt::log::format::inserter(
			_prefix
			+
			FCPPT_TEXT(": %1%")
		);
}
