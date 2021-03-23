//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_FILESYSTEM_PATH_TO_STRING_HPP_INCLUDED
#define FCPPT_FILESYSTEM_PATH_TO_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace filesystem
{
/**
\brief Turns a path into an fcppt::string

\ingroup fcpptfilesystem

Turns \a path into an fcppt::string.
*/
FCPPT_FILESYSTEM_DETAIL_SYMBOL
fcppt::string path_to_string(std::filesystem::path const &path);

}
}

#endif
