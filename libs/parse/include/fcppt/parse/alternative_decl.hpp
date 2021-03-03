//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_ALTERNATIVE_DECL_HPP_INCLUDED
#define FCPPT_PARSE_ALTERNATIVE_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/alternative_fwd.hpp>
#include <fcppt/parse/alternative_result.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
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
\brief Tries the left parser, and if that fails also the right parser. Uses the result of the first one that does not fail.

\ingroup fcpptparse

Let <code>l</code> and <code>r</code> be parsers and <code>al = alternative{l,r}</code>.
First, <code>al</code> saves the current position <code>pos</code>.
Then, <code>al</code> tries the parser <code>l</code>. If it succeeds, then its result is returned.
If it returns a fatal error then this error is returned.
Otherwise, <code>al</code> backtracks to <code>pos</code> and returns the result of <code>r</code>.

See #fcppt::parse::alternative_result for this parser's result type.
*/
template <typename Left, typename Right>
class alternative : private fcppt::parse::tag
{
public:
  alternative(Left &&, Right &&);

  using result_type = fcppt::parse::
      alternative_result<fcppt::parse::result_of<Left>, fcppt::parse::result_of<Right>>;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;

private:
  Left left_;

  Right right_;
};

FCPPT_PP_POP_WARNING

}
}

#endif
