//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_EXTENSION_WITHOUT_DOT_HPP_INCLUDED
#define FCPPT_FILESYSTEM_EXTENSION_WITHOUT_DOT_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief Returns the extension of a path as string without the dot

\ingroup fcpptfilesystem

Returns the extension of \a path without the dot as a string instead of a path.

\param path The path to return the extension from

\return The extension as a string without the dot. If there is no extension,
the string will be empty.
*/
FCPPT_FILESYSTEM_DETAIL_SYMBOL
fcppt::string
extension_without_dot(
	boost::filesystem::path const &path
);

}
}

#endif
