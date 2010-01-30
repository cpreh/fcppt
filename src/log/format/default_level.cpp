//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/format/default_level.hpp>
#include <fcppt/log/format/inserter.hpp>
#include <fcppt/log/level_to_string.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/text.hpp>

fcppt::log::format::const_object_ptr const
fcppt::log::format::default_level(
	level::type const level_
)
{
	return make_shared_ptr<
		inserter
	>(
		level_to_string(level_)
		+ FCPPT_TEXT(": %1%\n")
	);
}
