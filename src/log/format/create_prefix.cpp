//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/log/format/create_inserter.hpp>
#include <fcppt/log/format/create_prefix.hpp>
#include <fcppt/log/format/function.hpp>


fcppt::log::format::function const
fcppt::log::format::create_prefix(
	fcppt::string const &_prefix
)
{
	return
		fcppt::log::format::create_inserter(
			_prefix
			+ FCPPT_TEXT(": %1%")
		);
}
