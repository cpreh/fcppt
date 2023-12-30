//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_EXCLUDE_DECL_HPP_INCLUDED
#define FCPPT_PARSE_EXCLUDE_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/unit_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/exclude_fwd.hpp> // IWYU pragma: keep
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
\brief Matches only if another parser does not match.
\ingroup fcpptparse

<code>exclude{p1,p2}</code> is equivalent to <code>!p2 >> p1</code>.
*/
template <typename Parser, typename Exclude>
class exclude : private fcppt::parse::tag
{
public:
  static_assert(std::is_same_v<fcppt::parse::result_of<Exclude>,fcppt::unit>);

  explicit exclude(Parser &&, Exclude &&);

  using result_type = fcppt::parse::result_of<Parser>;

  template <typename Ch, typename Skipper>
  [[nodiscard]] fcppt::parse::result<Ch, result_type>
  parse(fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const;

private:
  Parser parser_;
  Exclude exclude_;
};

FCPPT_PP_POP_WARNING

}

#endif
