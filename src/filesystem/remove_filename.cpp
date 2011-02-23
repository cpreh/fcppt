//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/remove_filename.hpp>

fcppt::filesystem::path const
fcppt::filesystem::remove_filename(
	path _path
)
{
	_path.remove_filename();

	return _path;
}
