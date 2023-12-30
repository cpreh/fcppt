//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_IGNORE_DECL_HPP_INCLUDED
#define FCPPT_PARSE_IGNORE_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/unit_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/ignore_fwd.hpp> // IWYU pragma: keep
#include <fcppt/parse/result_fwd.hpp>
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
\brief Ignores the result of a parser.
\ingroup fcpptparse

If the parser p returns s on success, then <code>ignore{s}</code> returns fcppt::unit.
Errors returned by p remain unchanged.
*/
template <typename Parser>
class ignore : private fcppt::parse::tag
{
public:
  explicit ignore(Parser &&);

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
