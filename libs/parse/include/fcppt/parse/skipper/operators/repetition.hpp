//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_OPERATORS_REPETITION_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_OPERATORS_REPETITION_HPP_INCLUDED

#include <fcppt/parse/skipper/is_valid_argument.hpp>
#include <fcppt/parse/skipper/repetition_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
namespace skipper
{
/**
\brief Creates an #fcppt::parse::skipper::repetition.
\ingroup fcpptparse
*/
template <
    typename Parser,
    typename = std::enable_if_t<fcppt::parse::skipper::is_valid_argument<Parser>::value>>
fcppt::parse::skipper::repetition<fcppt::type_traits::remove_cv_ref_t<Parser>>
operator*(Parser &&_parser)
{
  return fcppt::parse::skipper::repetition<fcppt::type_traits::remove_cv_ref_t<Parser>>{
      std::forward<Parser>(_parser)};
}

}
}
}

#endif
