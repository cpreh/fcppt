//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_RECURSIVE_DECL_HPP_INCLUDED
#define FCPPT_PARSE_RECURSIVE_DECL_HPP_INCLUDED

#include <fcppt/recursive_fwd.hpp>
#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/recursive_fwd.hpp>
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
\brief Wraps a type in #fcppt::recursive.
\ingroup fcpptparse

<code>recursive{p}</code> is equivalent to
\code
construct<recursive<result_of<decltype(p)>)>>
\endcode
*/
template <typename Parser>
class recursive : private fcppt::parse::tag
{
public:
  explicit recursive(Parser &&);

  using result_type = fcppt::recursive<fcppt::parse::result_of<Parser>>;

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
