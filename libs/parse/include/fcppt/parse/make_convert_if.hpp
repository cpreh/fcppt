//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_MAKE_CONVERT_IF_HPP_INCLUDED
#define FCPPT_PARSE_MAKE_CONVERT_IF_HPP_INCLUDED

#include <fcppt/function_impl.hpp>
#include <fcppt/either/success_type.hpp>
#include <fcppt/parse/convert_if_impl.hpp>
#include <fcppt/parse/position_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Creates an #fcppt::parse::convert_if parser out of a lambda.
\ingroup fcpptparse

\param _parser The parser to convert from.
\param _convert The lambda function to use as conversion.
// TODO(philipp): Can we get rid of the Ch parameter?
*/
template <typename Ch, typename Parser, typename Convert>
fcppt::parse::convert_if<
    Ch,
    std::remove_cvref_t<Parser>,
    fcppt::either::success_type<std::invoke_result_t<
        Convert,
        fcppt::parse::position<Ch>,
        fcppt::parse::result_of<Parser> &&>>>
make_convert_if(Parser &&_parser, Convert &&_convert)
{
  using result_type =
      std::invoke_result_t<Convert, fcppt::parse::position<Ch>, fcppt::parse::result_of<Parser> &&>;

  return fcppt::parse::
      convert_if<Ch, std::remove_cvref_t<Parser>, fcppt::either::success_type<result_type>>{
          std::forward<Parser>(_parser),
          fcppt::function<result_type(
              fcppt::parse::position<Ch>, fcppt::parse::result_of<Parser> &&)>{
              std::forward<Convert>(_convert)}};
}
}

#endif
