//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_NOT_DECL_HPP_INCLUDED
#define FCPPT_PARSE_NOT_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/unit_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/not_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief Negates the result of a parser, returns nothing.
\ingroup fcpptparse

If the parser p returns a value, then <code>not_{p}</code> fails.
Otherwise, if p fails, then <code>not_{p}</code> returns #fcppt::unit.

\tparam Parser A parser that returns nothing.
*/
template <typename Parser>
class not_ : private fcppt::parse::tag
{
public:
  static_assert(std::is_same_v<fcppt::parse::result_of<Parser>,fcppt::unit>);

  explicit not_(Parser &&);

  using result_type = fcppt::unit;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;

private:
  Parser parser_;
};

FCPPT_PP_POP_WARNING

}

#endif
