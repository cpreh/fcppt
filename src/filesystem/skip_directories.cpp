//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/skip_directories.hpp>
#include <fcppt/filesystem/is_directory.hpp>

fcppt::filesystem::directory_iterator const
fcppt::filesystem::skip_directories(
	directory_iterator it
)
{
	while(
		it != directory_iterator()
		&& filesystem::is_directory(*it)
	)
		++it;

	return it;
}
