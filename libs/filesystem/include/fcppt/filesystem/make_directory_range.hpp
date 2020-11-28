//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_FILESYSTEM_MAKE_DIRECTORY_RANGE_HPP_INCLUDED
#define FCPPT_FILESYSTEM_MAKE_DIRECTORY_RANGE_HPP_INCLUDED

#include <fcppt/either/object_impl.hpp>
#include <fcppt/filesystem/directory_range.hpp>
#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <system_error>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace filesystem
{
/**
\brief Creates a directory range.

\ingroup fcpptfilesystem
*/
FCPPT_FILESYSTEM_DETAIL_SYMBOL
fcppt::either::object<std::error_code, fcppt::filesystem::directory_range>
make_directory_range(std::filesystem::path const &, std::filesystem::directory_options);

}
}

#endif
