//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_FILESYSTEM_STRIP_PREFIX_HPP_INCLUDED
#define FCPPT_FILESYSTEM_STRIP_PREFIX_HPP_INCLUDED

#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace filesystem
{
/**
\brief Strips a prefix from a path

\ingroup fcpptfilesystem

Strips \a prefix from \a path.

\warning The behavior is undefined if \a prefix is not a prefix of \a path

\param prefix The prefix path

\param path The path to strip the prefix from
*/
FCPPT_FILESYSTEM_DETAIL_SYMBOL
std::filesystem::path
strip_prefix(std::filesystem::path const &prefix, std::filesystem::path const &path);

}
}

#endif
