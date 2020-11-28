//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_FILESYSTEM_OPEN_EXN_HPP_INCLUDED
#define FCPPT_FILESYSTEM_OPEN_EXN_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/filesystem/open.hpp>
#include <fcppt/filesystem/path_to_string.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <ios>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace filesystem
{
/**
\brief Opens a file, throwing an exception on failure.

\ingroup fcpptfilesystem

Tries to open \a _path with \a _openmode and throw an exception on failure.

\tparam Stream Must be a std::{basic_ifstream,basic_ofstream,basic_fstream}.

\tparam Exception Must be constructible from #fcppt::string.
*/
template <typename Stream, typename Exception = fcppt::exception>
Stream open_exn(std::filesystem::path const &_path, std::ios_base::openmode const _openmode)
{
  return fcppt::optional::to_exception(fcppt::filesystem::open<Stream>(_path, _openmode), [&_path] {
    return Exception{FCPPT_TEXT("Failed to open ") + fcppt::filesystem::path_to_string(_path)};
  });
}

}
}

#endif
