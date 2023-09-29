//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_RUN_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_RUN_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/skipper/is_skipper_v.hpp>
#include <fcppt/parse/skipper/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse::skipper
{
/**
\brief Runs a skipper on a stream.
\ingroup fcpptparse
*/
template <typename Ch, typename Skipper, typename = std::enable_if_t<fcppt::parse::skipper::is_skipper_v<Skipper>>>
[[nodiscard]] fcppt::parse::skipper::result<Ch>
run(Skipper const &_skipper, fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state)
{
  return _skipper.skip(_state);
}

}

#endif
