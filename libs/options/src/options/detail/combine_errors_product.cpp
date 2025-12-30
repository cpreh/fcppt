//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/options/error.hpp>
#include <fcppt/options/error_product.hpp>
#include <fcppt/options/error_variant.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/missing_error_product.hpp>
#include <fcppt/options/missing_error_variant.hpp>
#include <fcppt/options/parse_error.hpp>
#include <fcppt/options/detail/combine_errors_product.hpp>
#include <fcppt/options/detail/missing_error_to_error.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/make_recursive.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::parse_error fcppt::options::detail::combine_errors_product(
    fcppt::options::missing_error_variant &&_left, fcppt::options::parse_error &&_right)
{
  return fcppt::variant::match(
      std::move(_right),
      // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
      [&_left](fcppt::options::missing_error &&_missing_error)
      {
        return fcppt::options::parse_error{fcppt::options::missing_error{
            std::move(_missing_error.state()),
            fcppt::options::missing_error_variant{fcppt::options::missing_error_product{
                fcppt::make_recursive(std::move(_left)),
                fcppt::make_recursive(std::move(_missing_error.error()))}}}};
      },
      [&_left](fcppt::options::error &&_other_error)
      {
        return fcppt::options::parse_error{
            fcppt::options::error{fcppt::options::error_variant{fcppt::options::error_product{
                fcppt::make_recursive(
                    fcppt::options::detail::missing_error_to_error(std::move(_left))),
                fcppt::make_recursive(std::move(_other_error))}}}};
      });
}
