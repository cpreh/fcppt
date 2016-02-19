//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/create_directories_recursive_exn.hpp>
#include <fcppt/filesystem/create_directory_failed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


void
fcppt::filesystem::create_directories_recursive_exn(
	boost::filesystem::path const &_path
)
{
	if(
		!boost::filesystem::create_directories(
			_path
		)
	)
		throw fcppt::filesystem::create_directory_failed(
			_path
		);
}
