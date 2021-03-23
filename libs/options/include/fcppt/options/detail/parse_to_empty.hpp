//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DETAIL_PARSE_TO_EMPTY_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_PARSE_TO_EMPTY_HPP_INCLUDED

#include <fcppt/either/match.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_error.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value.hpp>
#include <fcppt/options/detail/leftover_error.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace options
{
namespace detail
{
template <typename Parser>
fcppt::options::result<fcppt::options::result_of<Parser>> parse_to_empty(
    Parser const &_parser,
    fcppt::options::state &&_state,
    fcppt::options::parse_context const &_context)
{
  using result_type = fcppt::options::result_of<Parser>;

  using return_type = fcppt::options::result<result_type>;

  return fcppt::either::match(
      fcppt::options::deref(_parser).parse(std::move(_state), _context),
      [](fcppt::options::parse_error &&_parse_error) {
        return return_type{fcppt::variant::match(
            std::move(_parse_error),
            [](fcppt::options::missing_error &&_error) {
              return fcppt::options::error{std::move(_error.error())};
            },
            [](fcppt::options::other_error &&_error) {
              return fcppt::options::error{std::move(_error.get())};
            })};
      },
      [](fcppt::options::state_with_value<result_type> &&_result) {
        FCPPT_PP_PUSH_WARNING
        FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)

        return fcppt::optional::maybe(
            fcppt::options::detail::leftover_error(_result.state()),
            [&_result] { return return_type{std::move(_result.value())}; },
            [](fcppt::options::error &&_error) { return return_type{std::move(_error)}; });

        FCPPT_PP_POP_WARNING
      });
}

}
}
}

#endif
