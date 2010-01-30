//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/is_regular.hpp>
#include <boost/filesystem/operations.hpp>

bool
fcppt::filesystem::is_regular(
	path const &path_
)
{
	return boost::filesystem::is_regular_file(
		path_
	);
}
