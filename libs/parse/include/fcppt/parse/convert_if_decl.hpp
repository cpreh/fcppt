//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_CONVERT_IF_DECL_HPP_INCLUDED
#define FCPPT_PARSE_CONVERT_IF_DECL_HPP_INCLUDED

#include <fcppt/function_impl.hpp>
#include <fcppt/reference_fwd.hpp>
#include <fcppt/either/object_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/convert_if_fwd.hpp> // IWYU pragma: keep
#include <fcppt/parse/custom_error_fwd.hpp>
#include <fcppt/parse/position_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace fcppt::parse
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief Converts the success value of a parser into either another success value or an error.

\ingroup fcpptparse

If the parser p returns s, then <code>convert(p,f)</code> returns <code>f(s)</code>,
which can either be a success or an error value.
Errors returned by p remain unchanged.

\tparam Result The success type of this parser.
*/
template <typename Ch, typename Parser, typename Result>
class convert_if : private fcppt::parse::tag
{
public:
  using result_type = Result;

  using function_type =
      fcppt::function<fcppt::either::object<fcppt::parse::custom_error<Ch>, result_type>(
          fcppt::parse::position<Ch>, fcppt::parse::result_of<Parser> &&)>;

  convert_if(Parser &&, function_type &&);

  template <typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;

private:
  Parser parser_;

  function_type convert_;
};

FCPPT_PP_POP_WARNING

}

#endif
