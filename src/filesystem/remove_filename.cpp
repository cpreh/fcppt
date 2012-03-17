//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/remove_filename.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


boost::filesystem::path const
fcppt::filesystem::remove_filename(
	boost::filesystem::path const &_path
)
{
	boost::filesystem::path new_path(
		_path
	);

	new_path.remove_filename();

	return new_path;
}
