//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_ALTERNATIVE_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_ALTERNATIVE_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/set_position.hpp>
#include <fcppt/parse/detail/combine_errors.hpp>
#include <fcppt/parse/skipper/alternative_decl.hpp>
#include <fcppt/parse/skipper/make_failure.hpp>
#include <fcppt/parse/skipper/make_success.hpp>
#include <fcppt/parse/skipper/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Left, typename Right>
fcppt::parse::skipper::alternative<Left, Right>::alternative(Left &&_left, Right &&_right)
    : left_{std::move(_left)}, right_{std::move(_right)}
{
}

template <typename Left, typename Right>
template <typename Ch>
fcppt::parse::skipper::result<Ch>
fcppt::parse::skipper::alternative<Left, Right>::skip(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state) const
{
  fcppt::parse::position<Ch> const old_pos{fcppt::parse::get_position(_state)};

  return fcppt::either::match(
      fcppt::parse::deref(this->left_).skip(_state),
      [old_pos, &_state, this](fcppt::parse::error<Ch> &&_left_error)
      {
        fcppt::parse::set_position(_state, old_pos);

        return _left_error.is_fatal()
                   ? fcppt::parse::skipper::make_failure(std::move(_left_error))
                   : fcppt::either::match(
                         fcppt::parse::deref(this->right_).skip(_state),
                         [&_left_error](fcppt::parse::error<Ch> &&_right_error)
                         {
                           return fcppt::parse::skipper::make_failure(
                               fcppt::parse::detail::combine_errors(
                                   std::move(_left_error), std::move(_right_error)));
                         },
                         [](fcppt::either::no_error)
                         { return fcppt::parse::skipper::make_success<Ch>(); });
      },
      [](fcppt::either::no_error) { return fcppt::parse::skipper::make_success<Ch>(); });
}

#endif
