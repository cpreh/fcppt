//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/reference_impl.hpp>
#include <fcppt/filesystem/recursive_directory_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <system_error>
#include <fcppt/config/external_end.hpp>

fcppt::filesystem::recursive_directory_range::recursive_directory_range(
    std::filesystem::path const &_path,
    std::filesystem::directory_options const _options,
    fcppt::reference<std::error_code> const _error)
    : begin_{_path, _options, _error.get()}
{
}

std::filesystem::recursive_directory_iterator
fcppt::filesystem::recursive_directory_range::begin() const
{
  return this->begin_;
}

std::filesystem::recursive_directory_iterator
// NOLINTNEXTLINE(readability-convert-member-functions-to-static)
fcppt::filesystem::recursive_directory_range::end() const
{
  return std::filesystem::recursive_directory_iterator();
}
