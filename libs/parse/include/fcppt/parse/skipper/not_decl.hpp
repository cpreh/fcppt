//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_NOT_DECL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_NOT_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/skipper/not_fwd.hpp>
#include <fcppt/parse/skipper/result_fwd.hpp>
#include <fcppt/parse/skipper/tag.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::skipper
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief Negates the result of a skipper.
\ingroup fcpptparse

If the skipper p succeeds, then <code>not_{p}</code> fails.
Otherwise, if p fails, then <code>not_{p}</code> succeeds.
*/
template <typename Skipper>
class not_ : private fcppt::parse::skipper::tag
{
public:
  explicit not_(Skipper &&);

  template <typename Ch>
  [[nodiscard]] fcppt::parse::skipper::result<Ch>
  skip(fcppt::reference<fcppt::parse::basic_stream<Ch>>) const;
private:
  Skipper skipper_;
};

FCPPT_PP_POP_WARNING

}

#endif
