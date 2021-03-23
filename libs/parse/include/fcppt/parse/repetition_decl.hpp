//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_REPETITION_DECL_HPP_INCLUDED
#define FCPPT_PARSE_REPETITION_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/repetition_fwd.hpp>
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
\brief Tries a parser repeatedly, producing a vector of results.
\ingroup fcpptparse

Let <code>p</code> be a parser and <code>rep = repetition{p}</code>.
Initially, the result <code>r</code> is the empty vector.
A single parsing step consists of the following actions:
First, the current position <code>pos</code> is saved.
Then, the skipper is run. After that, the parser <code>p</code> is tried. If it succeeds with result <code>s</code>,
then <code>s</code> is added to <code>r</code>.
These steps continue as long as <code>p</code> does not return an error.
Once this happens, if the returned error is fatal, then <code>rep</code> also returns a fatal error.
Otherwise, <code>rep</code> backtracks to <code>pos</code> and returns <code>r</code>.
*/
template <typename Parser>
class repetition : private fcppt::parse::tag
{
public:
  explicit repetition(Parser &&);

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
