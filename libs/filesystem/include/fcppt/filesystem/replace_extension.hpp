//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_REPLACE_EXTENSION_HPP_INCLUDED
#define FCPPT_FILESYSTEM_REPLACE_EXTENSION_HPP_INCLUDED

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
\brief Replaces the extension of a path

\ingroup fcpptfilesystem

Replaces the extension of \a path with \a new_extension.

\param path The path to replace the extension of

\param new_extension The new extension, excluding the dot

\return A new path with the extension replaced
*/
FCPPT_FILESYSTEM_DETAIL_SYMBOL
boost::filesystem::path
replace_extension(
	boost::filesystem::path const &path,
	fcppt::string const &new_extension
);

}
}

#endif
