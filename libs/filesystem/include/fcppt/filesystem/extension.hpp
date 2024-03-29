//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_FILESYSTEM_EXTENSION_HPP_INCLUDED
#define FCPPT_FILESYSTEM_EXTENSION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>

namespace fcppt::filesystem
{
/**
\brief Returns the extension of a path as an #fcppt::string.

\ingroup fcpptfilesystem

\return The extension as an #fcppt::string. If there is no extension, the string will be
empty.
*/
[[nodiscard]]
FCPPT_FILESYSTEM_DETAIL_SYMBOL
fcppt::string extension(std::filesystem::path const &path);

}

#endif
