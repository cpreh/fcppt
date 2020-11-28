//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_EPSILON_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_EPSILON_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/skipper/epsilon_decl.hpp>
#include <fcppt/parse/skipper/make_success.hpp>
#include <fcppt/parse/skipper/result.hpp>

inline fcppt::parse::skipper::epsilon::epsilon() = default;

template <typename Ch>
fcppt::parse::skipper::result<Ch>
    fcppt::parse::skipper::epsilon::skip(fcppt::reference<fcppt::parse::basic_stream<Ch>>) const
{
  return fcppt::parse::skipper::make_success<Ch>();
}

#endif
