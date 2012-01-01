//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/is_regular.hpp>
#include <fcppt/filesystem/next_file.hpp>
#include <fcppt/filesystem/skip_directories.hpp>


fcppt::filesystem::directory_iterator const
fcppt::filesystem::next_file(
	filesystem::directory_iterator _it
)
{
	if(
		_it != directory_iterator()
		&& filesystem::is_regular(*_it)
	)
		++_it;

	return
		filesystem::skip_directories(
			_it
		);
}
