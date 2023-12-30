//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SEQUENCE_DECL_HPP_INCLUDED
#define FCPPT_PARSE_SEQUENCE_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/sequence_fwd.hpp> // IWYU pragma: keep
#include <fcppt/parse/sequence_result.hpp>
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
\brief Tries two parsers in succession. Produces a tuple of both results if both parsers do not fail.
\ingroup fcpptparse

Let <code>l</code> and <code>r</code> be parsers and <code>seq = sequence{l,r}</code>.
First, the skipper is run. Then, <code>seq</code> tries the parser <code>l</code>.
If it succeeds, then the skipper is run again. After that, <code>seq</code> also tries <code>r</code>.
If <code>r</code> also succeeds, then the tuple of both results is returned.
Otherwise, the first error is returned.

See #fcppt::parse::sequence_result for this parser's result type.
*/
template <typename Left, typename Right>
class sequence : private fcppt::parse::tag
{
public:
  sequence(Left &&, Right &&);

  using result_type =
      fcppt::parse::sequence_result<fcppt::parse::result_of<Left>, fcppt::parse::result_of<Right>>;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;

private:
  Left left_;

  Right right_;
};

FCPPT_PP_POP_WARNING

}

#endif
