//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/is_directory.hpp>
#include <fcppt/filesystem/skip_directories.hpp>


fcppt::filesystem::directory_iterator const
fcppt::filesystem::skip_directories(
	filesystem::directory_iterator _it
)
{
	while(
		_it != directory_iterator()
		&& filesystem::is_directory(*_it)
	)
		++_it;

	return _it;
}
