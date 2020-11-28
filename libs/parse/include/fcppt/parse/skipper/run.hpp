//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_RUN_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_RUN_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/skipper/is_skipper.hpp>
#include <fcppt/parse/skipper/result.hpp>

namespace fcppt
{
namespace parse
{
namespace skipper
{
template <typename Ch, typename Skipper>
[[nodiscard]] fcppt::parse::skipper::result<Ch>
run(Skipper const &_skipper, fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state)
{
  static_assert(fcppt::parse::skipper::is_skipper<Skipper>::value);

  return _skipper.skip(_state);
}

}
}
}

#endif
