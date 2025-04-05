//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/const.hpp>
#include <fcppt/filesystem/file_size.hpp>
#include <fcppt/filesystem/optional_size.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <filesystem>
#include <system_error>
#include <fcppt/config/external_end.hpp>

fcppt::filesystem::optional_size fcppt::filesystem::file_size(std::filesystem::path const &_path) noexcept
{
  std::error_code res{};

  std::uintmax_t const size{std::filesystem::file_size(_path, res)};

  // NOLINTNEXTLINE(modernize-use-integer-sign-comparison)
  return fcppt::optional::make_if(size != static_cast<std::uintmax_t>(-1), fcppt::const_(size));
}
