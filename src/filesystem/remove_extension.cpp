//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/remove_extension.hpp>
#include <fcppt/filesystem/path_to_string.hpp>
#include <fcppt/filesystem/remove_filename.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>

fcppt::filesystem::path const
fcppt::filesystem::remove_extension(
	path const &_path
)
{
	if(
		!_path.has_filename()
	)
		return _path;

	fcppt::string filename(
		fcppt::filesystem::path_to_string(
			_path.filename()
		)
	);

	fcppt::string::size_type const pos(
		filename.find_last_of(
			FCPPT_TEXT('.')
		)
	);

	if(
		pos == fcppt::string::npos
	)
		return _path;
	
	filename.erase(
		pos,
		fcppt::string::npos
	);

	return
		fcppt::filesystem::remove_filename(
			_path
		)
		/ filename;
}
