//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_FILE_TO_STRING_HPP_INCLUDED
#define FCPPT_FILESYSTEM_FILE_TO_STRING_HPP_INCLUDED

#include <fcppt/optional_string.hpp>
#include <fcppt/filesystem/detail/symbol.hpp>
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

Returns the contents of the file denoted by \a path as string if the file
exists and can be read, otherwise returns the empty optional.

\throw fcppt::exception if the file is too large. This can happen
if <code>std::size_t</code> is too small (e.g. on a 32bit system) to hold all
file sizes.
*/
FCPPT_FILESYSTEM_DETAIL_SYMBOL
fcppt::optional_string
file_to_string(
	boost::filesystem::path const &path
);

}
}

#endif
