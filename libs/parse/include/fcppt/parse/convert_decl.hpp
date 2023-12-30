//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_CONVERT_DECL_HPP_INCLUDED
#define FCPPT_PARSE_CONVERT_DECL_HPP_INCLUDED

#include <fcppt/function_impl.hpp>
#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/convert_fwd.hpp> // IWYU pragma: keep
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
\brief Converts the success value of a parser into another success value.

\ingroup fcpptparse

If the parser p returns s, then <code>convert(p,f)</code> returns the success value <code>f(s)</code>.
Errors returned by p remain unchanged.

\tparam Result The success type of this parser.
*/
template <typename Parser, typename Result>
class convert : private fcppt::parse::tag
{
public:
  using result_type = Result;

  using function_type = fcppt::function<result_type(fcppt::parse::result_of<Parser> &&)>;

  convert(Parser &&, function_type &&);

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;

private:
  Parser parser_;

  function_type convert_;
};

FCPPT_PP_POP_WARNING

}

#endif
