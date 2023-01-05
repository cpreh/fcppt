//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_FAIL_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_FAIL_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/make_failure.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/fail_decl.hpp>
#include <fcppt/parse/fail_error_impl.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/parse/result.hpp>

template <typename Result>
fcppt::parse::fail<Result>::fail() = default;

template <typename Result>
template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::fail<Result>::result_type>
fcppt::parse::fail<Result>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &) const
{
  return fcppt::either::make_failure<result_type>(fcppt::parse::error<Ch>{
      fcppt::parse::error_variant<Ch>{
          fcppt::parse::fail_error<Ch>{fcppt::parse::get_position(_state)}},
      fcppt::parse::is_fatal{false}});
}

#endif
