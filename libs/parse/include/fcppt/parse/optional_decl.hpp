//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_OPTIONAL_DECL_HPP_INCLUDED
#define FCPPT_PARSE_OPTIONAL_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/optional_fwd.hpp> // IWYU pragma: keep
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
\brief Makes a parser optional.
\ingroup fcpptparse

Let <code>p</code> be a parser and let <code>o = optional{p}</code>.
First, <code>o</code> saves the current position <code>pos</code>
and then tries <code>p</code>.
If <code>p</code> succeeds, then its result is returned.
Otherwise, <code>o</code> backtracks to <code>pos</code>.
If the returned error is fatal, then <code>o</code> also returns it.
Otherwise, <code>o</code> returns the empty optional.
*/
template <typename Parser>
class optional : private fcppt::parse::tag
{
public:
  explicit optional(Parser &&);

  using result_type = fcppt::optional::object<fcppt::parse::result_of<Parser>>;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;

private:
  Parser parser_;
};

FCPPT_PP_POP_WARNING

}

#endif
