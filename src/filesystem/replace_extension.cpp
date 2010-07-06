//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/replace_extension.hpp>
#include <fcppt/text.hpp>

fcppt::filesystem::path const
fcppt::filesystem::replace_extension(
	path const &p,
	string const &ext
)
{
	return
		path(p).replace_extension(
			ext
		);
}
