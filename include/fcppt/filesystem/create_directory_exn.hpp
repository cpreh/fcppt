//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_CREATE_DIRECTORY_EXN_HPP_INCLUDED
#define FCPPT_FILESYSTEM_CREATE_DIRECTORY_EXN_HPP_INCLUDED

#include <fcppt/filesystem/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Tries to create a directory

\ingroup fcpptfilesystem

Tries to create the last component of \a path as a directory.

\param path The path to create the last component of

\throw fcppt::filesystem::create_directory_failed if creating the directory is
not successful
*/
FCPPT_FILESYSTEM_SYMBOL
void
create_directory_exn(
	boost::filesystem::path const &path
);

}
}

#endif
