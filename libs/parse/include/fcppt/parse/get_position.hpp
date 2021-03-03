//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_GET_POSITION_HPP_INCLUDED
#define FCPPT_PARSE_GET_POSITION_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/basic_stream_impl.hpp>
#include <fcppt/parse/position.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief The current position of a stream.
\ingroup fcpptparse
*/
template <typename Ch>
fcppt::parse::position<Ch>
get_position(fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state)
{
  return _state.get().get_position();
}

}
}

#endif
