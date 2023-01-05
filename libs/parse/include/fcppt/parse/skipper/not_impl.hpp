//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_NOT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_NOT_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/fail_error_impl.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/set_position.hpp>
#include <fcppt/parse/skipper/make_failure.hpp>
#include <fcppt/parse/skipper/make_success.hpp>
#include <fcppt/parse/skipper/not_decl.hpp>
#include <fcppt/parse/skipper/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Skipper>
fcppt::parse::skipper::not_<Skipper>::not_(Skipper &&_skipper) : skipper_{std::move(_skipper)}
{
}

template <typename Skipper>
template <typename Ch>
fcppt::parse::skipper::result<Ch> fcppt::parse::skipper::not_<Skipper>::skip(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state) const
{
  fcppt::parse::position<Ch> const pos{fcppt::parse::get_position(_state)};

  bool const has_value{fcppt::parse::deref(this->skipper_).skip(_state).has_success()};

  fcppt::parse::set_position(_state, pos);

  return has_value ? fcppt::parse::skipper::make_failure(fcppt::parse::error<Ch>{
                         fcppt::parse::error_variant<Ch>{fcppt::parse::fail_error<Ch>{pos}},
                         fcppt::parse::is_fatal{false}})
                   : fcppt::parse::skipper::make_success<Ch>();
}

#endif
