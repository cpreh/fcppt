//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_REMOVE_EXTENSION_HPP_INCLUDED
#define FCPPT_FILESYSTEM_REMOVE_EXTENSION_HPP_INCLUDED

#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Removes the extension from a path

\ingroup fcpptfilesystem

Removes the extension (inluding the dot) from \a path if it has any.

\param path The path to remove the extension from

\return A new path with the extension removed
*/
FCPPT_FILESYSTEM_DETAIL_SYMBOL
boost::filesystem::path
remove_extension(
	boost::filesystem::path const &path
);

}
}

#endif
