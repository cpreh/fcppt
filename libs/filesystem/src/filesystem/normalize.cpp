//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/text.hpp>
#include <fcppt/filesystem/normalize.hpp>
#include <fcppt/filesystem/stem.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>

std::filesystem::path fcppt::filesystem::normalize(std::filesystem::path const &_path)
{
  return fcppt::filesystem::stem(_path) == FCPPT_TEXT(".")
             ? std::filesystem::path(_path).remove_filename()
             : _path;
}
