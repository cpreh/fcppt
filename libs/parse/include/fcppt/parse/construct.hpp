//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_CONSTRUCT_HPP_INCLUDED
#define FCPPT_PARSE_CONSTRUCT_HPP_INCLUDED

#include <fcppt/parse/convert_impl.hpp>
#include <fcppt/parse/make_convert.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
/**
\brief Applies a constructor to the result of a parser.
\ingroup fcpptparse

If the parser p returns s on success, then <code>construct(p)</code> returns <code>Result{s}</code> on success.
Errors remain unchanged.
*/
template <typename Result, typename Parser>
fcppt::parse::convert<std::remove_cvref_t<Parser>, Result>
construct(Parser &&_parser)
{
  return fcppt::parse::make_convert(
      std::forward<Parser>(_parser),
      [](fcppt::parse::result_of<Parser> &&_value) { return Result{std::move(_value)}; });
}

}

#endif
