//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_FILESYSTEM_OPEN_HPP_INCLUDED
#define FCPPT_FILESYSTEM_OPEN_HPP_INCLUDED

#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <ios>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace filesystem
{
/**
\brief Opens a file, returning an optional.

\ingroup fcpptfilesystem

Tries to open \a _path with \a _openmode and returns an empty optional on
failure.

\tparam Stream Must be a std::{basic_ifstream,basic_ofstream,basic_fstream}.
*/
template <typename Stream>
fcppt::optional::object<Stream>
open(std::filesystem::path const &_path, std::ios_base::openmode const _openmode)
{
  Stream result{};

  result.open(_path, _openmode);

  return fcppt::optional::make_if(result.is_open(), [&result] { return std::move(result); });
}

}
}

#endif
