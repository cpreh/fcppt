//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/create_directories_recursive.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/convenience.hpp>
#include <fcppt/config/external_end.hpp>

bool
fcppt::filesystem::create_directories_recursive(
	filesystem::path const &_path
)
{
	return
		boost::filesystem::create_directories(
			_path
		);
}
