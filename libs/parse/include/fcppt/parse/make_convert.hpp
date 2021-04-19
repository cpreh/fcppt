//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_MAKE_CONVERT_HPP_INCLUDED
#define FCPPT_PARSE_MAKE_CONVERT_HPP_INCLUDED

#include <fcppt/function_impl.hpp>
#include <fcppt/parse/convert_impl.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief Creates an #fcppt::parse::convert parser out of a lambda.
\ingroup fcpptparse

\param _parser The parser to convert from.
\param _convert The lambda function to use as conversion.
*/
template <typename Parser, typename Convert>
fcppt::parse::convert<
    fcppt::type_traits::remove_cv_ref_t<Parser>,
    std::invoke_result_t<Convert,fcppt::parse::result_of<Parser> &&>>
make_convert(Parser &&_parser, Convert &&_convert)
{
  using result_type = std::invoke_result_t<Convert,fcppt::parse::result_of<Parser> &&>;

  return fcppt::parse::convert<fcppt::type_traits::remove_cv_ref_t<Parser>, result_type>{
      std::forward<Parser>(_parser),
      fcppt::function<result_type(fcppt::parse::result_of<Parser> &&)>{
          std::forward<Convert>(_convert)}};
}

}
}

#endif
