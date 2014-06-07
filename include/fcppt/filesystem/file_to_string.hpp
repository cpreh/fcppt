//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_FILE_TO_STRING_HPP_INCLUDED
#define FCPPT_FILESYSTEM_FILE_TO_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/filesystem/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Returns the contents of a file as a string

\ingroup fcpptfilesystem

Returns the contents of the file denoted by \a path as string.

\param path The file to turn into a string

\return The contents of the file as s string

\throw fcppt::filesystem::exception if anything goes wrong
*/
FCPPT_FILESYSTEM_SYMBOL
fcppt::string
file_to_string(
	boost::filesystem::path const &path
);

}
}

#endif
