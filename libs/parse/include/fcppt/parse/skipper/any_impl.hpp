//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_ANY_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_ANY_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/construct.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/parse/basic_char_error_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/get_char.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/skipper/any_decl.hpp> // IWYU pragma: export
#include <fcppt/parse/skipper/result.hpp>

inline fcppt::parse::skipper::any::any() = default;

template <typename Ch>
fcppt::parse::skipper::result<Ch> fcppt::parse::skipper::any::skip(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state) const
{
  fcppt::parse::position<Ch> const pos{fcppt::parse::get_position(_state)};

  return fcppt::either::construct(
      fcppt::parse::get_char(_state).has_value(),
      [] { return fcppt::either::no_error{}; },
      [pos]
      {
        return fcppt::parse::error<Ch>{
            fcppt::parse::error_variant<Ch>{fcppt::parse::basic_char_error<Ch>{pos}},
            fcppt::parse::is_fatal{false}};
      });
}

#endif
