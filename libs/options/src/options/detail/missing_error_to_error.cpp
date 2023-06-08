//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_recursive.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/error_pair.hpp>
#include <fcppt/options/error_variant.hpp>
#include <fcppt/options/missing_error_variant.hpp>
#include <fcppt/options/detail/missing_error_to_error.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::error
fcppt::options::detail::missing_error_to_error(fcppt::options::missing_error_variant &&_error)
{
  return fcppt::variant::match(
      std::move(_error),
      [](fcppt::options::missing_argument_error &&_inner)
      { return fcppt::options::error{fcppt::options::error_variant{std::move(_inner)}}; },
      [](fcppt::options::missing_command_error &&_inner)
      { return fcppt::options::error{fcppt::options::error_variant{std::move(_inner)}}; },
      [](fcppt::options::missing_error_pair &&_inner)
      {
        return fcppt::options::error{fcppt::options::error_variant{fcppt::options::error_pair{
            fcppt::make_recursive(
                fcppt::options::detail::missing_error_to_error(std::move(_inner.left().get()))),
            fcppt::make_recursive(
                fcppt::options::detail::missing_error_to_error(std::move(_inner.right().get())))}}};
      },
      [](fcppt::options::missing_flag_error &&_inner)
      { return fcppt::options::error{fcppt::options::error_variant{std::move(_inner)}}; },
      [](fcppt::options::missing_option_error &&_inner)
      { return fcppt::options::error{fcppt::options::error_variant{std::move(_inner)}}; });
}
