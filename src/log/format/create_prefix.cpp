//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/format/create_prefix.hpp>
#include <fcppt/log/format/inserter.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/text.hpp>

fcppt::log::format::const_object_ptr const
fcppt::log::format::create_prefix(
	string const &prefix
)
{
	return
		make_shared_ptr<
			inserter
		>(
			prefix + FCPPT_TEXT(": %1%")
		);
}
