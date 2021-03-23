//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_CONVERT_CONST_DECL_HPP_INCLUDED
#define FCPPT_PARSE_CONVERT_CONST_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/unit_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/convert_const_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief Replaces the success value of a parser with a constant.

\ingroup fcpptparse

If the parser p returns s, then <code>convert_const(p,r)</code> returns <code>r</code>.
Errors remain unchanged.

\tparam Result The success type of this parser.
\tparam Parser A parser with no result.
*/
template <typename Parser, typename Result>
class convert_const : private fcppt::parse::tag
{
public:
  static_assert(std::is_same_v<fcppt::parse::result_of<Parser>,fcppt::unit>);

  convert_const(Parser &&, Result &&);

  using result_type = Result;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;

private:
  Parser parser_;

  Result result_;
};

FCPPT_PP_POP_WARNING

template <typename Parser, typename Result>
convert_const(Parser &&, Result &&) -> convert_const<
    fcppt::type_traits::remove_cv_ref_t<Parser>,
    fcppt::type_traits::remove_cv_ref_t<Result>>;

}
}

#endif
