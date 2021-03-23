//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/filesystem/remove_extension.hpp>
#include <fcppt/filesystem/stem.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>

std::filesystem::path fcppt::filesystem::remove_extension(std::filesystem::path const &_path)
{
  return _path.parent_path() /
         // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
         fcppt::filesystem::stem(_path);
}
