//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/first_file.hpp>
#include <fcppt/filesystem/skip_directories.hpp>
#include <fcppt/filesystem/directory_iterator.hpp>

fcppt::filesystem::directory_iterator const
fcppt::filesystem::first_file(
	filesystem::path const &_path
)
{
	return
		filesystem::skip_directories(
			filesystem::directory_iterator(
				_path
			)
		);
}
