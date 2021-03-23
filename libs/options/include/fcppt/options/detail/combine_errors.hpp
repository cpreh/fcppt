//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_COMBINE_ERRORS_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_COMBINE_ERRORS_HPP_INCLUDED

#include <fcppt/options/parse_error.hpp>
#include <fcppt/options/detail/combine_errors_impl.hpp>
#include <fcppt/variant/apply.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace options
{
namespace detail
{
template <typename Function>
inline fcppt::options::parse_error combine_errors(
    fcppt::options::parse_error &&_error1,
    fcppt::options::parse_error &&_error2,
    Function const &_function)
{
  return fcppt::variant::apply(
      [&_function](auto &&_val1, auto &&_val2) {
        return fcppt::options::parse_error{fcppt::options::detail::combine_errors_impl(
            std::forward<decltype(_val1)>(_val1), std::forward<decltype(_val2)>(_val2), _function)};
      },
      std::move(_error1),
      std::move(_error2));
}

}
}
}

#endif
