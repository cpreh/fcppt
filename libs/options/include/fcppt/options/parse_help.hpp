//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_PARSE_HELP_HPP_INCLUDED
#define FCPPT_OPTIONS_PARSE_HELP_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/options/deref.hpp>
#include <fcppt/options/help_result.hpp>
#include <fcppt/options/help_switch.hpp>
#include <fcppt/options/left.hpp>
#include <fcppt/options/make_sum.hpp>
#include <fcppt/options/parse_context.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/right.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/parse_to_empty.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::options
{
/**
\brief Parse a command-line with a help parser.

\ingroup fcpptoptions

First, the switch parser \a _help is applied to \a _args. If its switch <b>and
nothing else</b> is specified, the <code>usage</code> string is gathered from
\a _parser and returned.  Otherwise, if the switch of \a _help was not
specified, then the result of applying \a _parser to \a _args is returned.

\warning Do not include any short or long names in \a _parser that \a _help is using.
*/
template <typename Parser>
fcppt::options::help_result<fcppt::options::result_of<Parser>> parse_help(
    fcppt::options::help_switch const &_help,
    Parser const &_parser,
    fcppt::args_vector const &_args)
{
  using return_type = fcppt::options::help_result<fcppt::options::result_of<Parser>>;

  using result_type = fcppt::options::result<fcppt::options::result_of<Parser>>;

  FCPPT_RECORD_MAKE_LABEL(label);

  auto const combined_parser{
      fcppt::options::make_sum<label>(fcppt::make_cref(_help), fcppt::make_cref(_parser))};

  using sum_type = decltype(combined_parser);

  return fcppt::either::match(
      fcppt::options::detail::parse_to_empty(
          combined_parser,
          fcppt::options::state{fcppt::args_vector{_args}},
          fcppt::options::parse_context{combined_parser.option_names()}),
      [](fcppt::options::error &&_error) { return return_type{result_type{std::move(_error)}}; },
      [&_parser](fcppt::options::result_of<sum_type> &&_result) {
        FCPPT_PP_PUSH_WARNING
        FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)

        return fcppt::variant::match(
            std::move(fcppt::record::get<label>(_result)),
            [&_parser](
                fcppt::options::left<fcppt::options::result_of<typename sum_type::left>> &&) {
              return return_type{fcppt::options::deref(_parser).usage()};
            },
            [](fcppt::options::right<fcppt::options::result_of<typename sum_type::right>>
                   &&_inner_result) {
              return return_type{result_type{std::move(_inner_result.get())}};
            });

        FCPPT_PP_POP_WARNING
      });
}

}

#endif
