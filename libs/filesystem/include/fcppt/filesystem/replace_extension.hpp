//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_FILESYSTEM_REPLACE_EXTENSION_HPP_INCLUDED
#define FCPPT_FILESYSTEM_REPLACE_EXTENSION_HPP_INCLUDED

#include <fcppt/string_view.hpp>
#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>

namespace fcppt::filesystem
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
std::filesystem::path
replace_extension(std::filesystem::path const &path, fcppt::string_view new_extension);

}

#endif
