//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_OPERATORS_SEQUENCE_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_OPERATORS_SEQUENCE_HPP_INCLUDED

#include <fcppt/parse/skipper/is_valid_argument.hpp>
#include <fcppt/parse/skipper/sequence_impl.hpp>
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
template <
    typename Left,
    typename Right,
    typename = std::enable_if_t<std::conjunction_v<
        fcppt::parse::skipper::is_valid_argument<Left>,
        fcppt::parse::skipper::is_valid_argument<Right>>>>
fcppt::parse::skipper::
    sequence<fcppt::type_traits::remove_cv_ref_t<Left>, fcppt::type_traits::remove_cv_ref_t<Right>>
    operator>>(Left &&_left, Right &&_right)
{
  return fcppt::parse::skipper::sequence<
      fcppt::type_traits::remove_cv_ref_t<Left>,
      fcppt::type_traits::remove_cv_ref_t<Right>>{
      std::forward<Left>(_left), std::forward<Right>(_right)};
}

}
}
}

#endif
