//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_REMOVE_FILENAME_HPP_INCLUDED
#define FCPPT_FILESYSTEM_REMOVE_FILENAME_HPP_INCLUDED

#include <fcppt/filesystem/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Removes the filename from a path

\ingroup fcpptfilesystem

Removes the filename from \a path if it has any.

\param path The path to remove the filename from

\return A new path with the filename removed
*/
FCPPT_FILESYSTEM_SYMBOL
boost::filesystem::path const
remove_filename(
	boost::filesystem::path const &path
);

}
}

#endif
