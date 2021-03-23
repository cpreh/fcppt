//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/either/object_impl.hpp>
#include <fcppt/filesystem/directory_range.hpp>
#include <fcppt/filesystem/make_directory_range.hpp>
#include <fcppt/filesystem/impl/make_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <system_error>
#include <fcppt/config/external_end.hpp>

fcppt::either::object<std::error_code, fcppt::filesystem::directory_range>
fcppt::filesystem::make_directory_range(
    std::filesystem::path const &_path, std::filesystem::directory_options const _options)
{
  return fcppt::filesystem::impl::make_range<fcppt::filesystem::directory_range>(_path, _options);
}
