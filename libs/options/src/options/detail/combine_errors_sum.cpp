//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/make_recursive.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/error_sum.hpp>
#include <fcppt/options/error_variant.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/missing_error_sum.hpp>
#include <fcppt/options/missing_error_variant.hpp>
#include <fcppt/options/parse_error.hpp>
#include <fcppt/options/detail/combine_errors_sum.hpp>
#include <fcppt/options/detail/missing_error_to_error.hpp>
#include <fcppt/variant/apply.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace
{
inline fcppt::options::missing_error combine_errors_sum_impl(
    // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
    fcppt::options::missing_error &&_error1, fcppt::options::missing_error &&_error2)
{
  return fcppt::options::missing_error{
      std::move(_error2.state()),
      fcppt::options::missing_error_variant{fcppt::options::missing_error_sum{
          std::move(_error1.error()), std::move(_error2.error())}}};
}

inline fcppt::options::error
combine_errors_sum_impl(fcppt::options::error &&_error1, fcppt::options::error &&_error2)
{
  return fcppt::options::error{fcppt::options::error_variant{
      fcppt::options::error_sum{std::move(_error1), std::move(_error2)}}};
}

inline fcppt::options::error combine_errors_sum_impl(
    fcppt::options::error &&_error1,
    // NOLINTNEXTLINE(cppcoreguidelines-rvalue-reference-param-not-moved)
    fcppt::options::missing_error &&_error2)
{
  return combine_errors_sum_impl(
      std::move(_error1),
      fcppt::options::detail::missing_error_to_error(std::move(_error2.error())));
}

inline fcppt::options::error combine_errors_sum_impl(
    fcppt::options::missing_error &&_error1,
    fcppt::options::error &&_error2)
{
  return combine_errors_sum_impl(std::move(_error2), std::move(_error1));
}

}

fcppt::options::parse_error fcppt::options::detail::combine_errors_sum(
    fcppt::options::parse_error &&_error1, fcppt::options::parse_error &&_error2)
{
  return fcppt::variant::apply(
      [](auto &&_val1, auto &&_val2)
      {
        return fcppt::options::parse_error{combine_errors_sum_impl(
            std::forward<decltype(_val1)>(_val1), std::forward<decltype(_val2)>(_val2))};
      },
      std::move(_error1),
      std::move(_error2));
}
