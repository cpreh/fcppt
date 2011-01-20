//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/first_file.hpp>
#include <fcppt/filesystem/skip_directories.hpp>

fcppt::filesystem::directory_iterator const
fcppt::filesystem::first_file(
	path const &p
)
{
	return
		skip_directories(
			directory_iterator(p)
		);
}
