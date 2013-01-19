//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_IS_EXECUTABLE_HPP_INCLUDED
#define FCPPT_FILESYSTEM_IS_EXECUTABLE_HPP_INCLUDED

#include <fcppt/filesystem/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Returns if a file is executable

\ingroup fcpptfilesystem

Returns if the file denoted by \a path is executable.

\param path The file to check

\throw fcppt::filesystem::exception if the file is not accessible
*/
FCPPT_FILESYSTEM_SYMBOL
bool
is_executable(
	boost::filesystem::path const &path
);

}
}

#endif
