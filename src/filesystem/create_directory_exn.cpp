//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/create_directory_exn.hpp>
#include <fcppt/filesystem/create_directory.hpp>
#include <fcppt/filesystem/create_directory_failed.hpp>

void
fcppt::filesystem::create_directory_exn(
	filesystem::path const &_path
)
{
	if(
		!fcppt::filesystem::create_directory(
			_path
		)
	)
		throw filesystem::create_directory_failed(
			_path
		);
}
