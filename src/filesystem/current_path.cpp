//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/current_path.hpp>
#include <boost/filesystem/operations.hpp>
#include <fcppt/filesystem/config.hpp>

fcppt::filesystem::path const
fcppt::filesystem::current_path()
{
#ifndef FCPPT_USE_FILESYSTEM_V3
	return boost::filesystem::current_path<path>();
#else
	return boost::filesystem::current_path();
#endif
}
