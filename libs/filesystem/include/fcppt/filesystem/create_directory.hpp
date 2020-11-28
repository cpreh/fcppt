//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_FILESYSTEM_CREATE_DIRECTORY_HPP_INCLUDED
#define FCPPT_FILESYSTEM_CREATE_DIRECTORY_HPP_INCLUDED

#include <fcppt/optional_error_code.hpp>
#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace filesystem
{
/**
\brief Tries to create a directory

\ingroup fcpptfilesystem

Tries to create the last component of \a path as a directory.
*/
[[nodiscard]] FCPPT_FILESYSTEM_DETAIL_SYMBOL fcppt::optional_error_code
create_directory(std::filesystem::path const &path);

}
}

#endif
