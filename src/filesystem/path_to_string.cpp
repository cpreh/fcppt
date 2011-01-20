//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/path_to_string.hpp>
#include <fcppt/filesystem/config.hpp>

fcppt::string const
fcppt::filesystem::path_to_string(
	fcppt::filesystem::path const &_path
)
{
	return
#ifdef FCPPT_USE_FILESYSTEM_V3
		_path.string<
			fcppt::string
		>();
#else
		_path.string();
#endif
}
