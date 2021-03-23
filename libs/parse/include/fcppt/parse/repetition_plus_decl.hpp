//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_REPETITION_PLUS_DECL_HPP_INCLUDED
#define FCPPT_PARSE_REPETITION_PLUS_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/repetition_plus_fwd.hpp>
#include <fcppt/parse/repetition_result.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace fcppt
{
namespace parse
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief Tries a parser repeatedly, producing a vector of results. Must produce at least one element.
\ingroup fcpptparse

This is identical to #fcppt::parse::repetition, but it returns an error in case no results are produced.

\see fcppt::parse::repetition
*/
template <typename Parser>
class repetition_plus : private fcppt::parse::tag
{
public:
  explicit repetition_plus(Parser &&);

  using result_type = fcppt::parse::repetition_result<fcppt::parse::result_of<Parser>>;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;

private:
  Parser parser_;
};

FCPPT_PP_POP_WARNING

}
}

#endif
