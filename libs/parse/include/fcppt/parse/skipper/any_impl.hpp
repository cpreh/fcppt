//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_ANY_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_ANY_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/get_char_error.hpp>
#include <fcppt/parse/skipper/any_decl.hpp>
#include <fcppt/parse/skipper/make_success.hpp>
#include <fcppt/parse/skipper/result.hpp>

inline fcppt::parse::skipper::any::any() = default;

template <typename Ch>
fcppt::parse::skipper::result<Ch> fcppt::parse::skipper::any::skip(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state) const
{
  return fcppt::either::map(
      fcppt::parse::get_char_error(_state), [](Ch) { return fcppt::either::no_error{}; });
}

#endif
