//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_CREATE_DIRECTORIES_RECURSIVE_EXN_HPP_INCLUDED
#define FCPPT_FILESYSTEM_CREATE_DIRECTORIES_RECURSIVE_EXN_HPP_INCLUDED

#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Tries to creates directories recursively

\ingroup fcpptfilesystem

For each nonexistant sub directory of \a path, it is tried to create that
directory.

\param path The path to create directories recursively

\throw fcppt::filesystem::create_directory_failed if creating one of the
directories is not successful
*/
FCPPT_FILESYSTEM_DETAIL_SYMBOL
void
create_directories_recursive_exn(
	boost::filesystem::path const &path
);

}
}

#endif
