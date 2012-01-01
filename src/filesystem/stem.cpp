//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/filesystem/path_to_string.hpp>
#include <fcppt/filesystem/stem.hpp>


fcppt::string const
fcppt::filesystem::stem(
	filesystem::path const &_path
)
{
	return
		fcppt::filesystem::path_to_string(
			_path.stem()
		);
}
