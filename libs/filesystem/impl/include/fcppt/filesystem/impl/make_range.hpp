//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_FILESYSTEM_IMPL_MAKE_RANGE_HPP_INCLUDED
#define FCPPT_FILESYSTEM_IMPL_MAKE_RANGE_HPP_INCLUDED

#include <fcppt/make_optional_error_code.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/either/error_from_optional.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/filesystem/directory_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <system_error>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace filesystem
{
namespace impl
{
template <typename Range>
fcppt::either::object<std::error_code, Range>
make_range(std::filesystem::path const &_path, std::filesystem::directory_options const _options)
{
  std::error_code error{};

  Range result{_path, _options, fcppt::make_ref(error)};

  return fcppt::either::map(
      fcppt::either::error_from_optional(fcppt::make_optional_error_code(error)),
      [&result](fcppt::either::no_error const &) { return result; });
}

}
}
}

#endif
