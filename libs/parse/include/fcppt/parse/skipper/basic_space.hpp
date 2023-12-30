//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_BASIC_SPACE_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_BASIC_SPACE_HPP_INCLUDED

#include <fcppt/parse/space_set.hpp>
#include <fcppt/parse/skipper/basic_char_set.hpp>
#include <fcppt/parse/skipper/operators/repetition.hpp> // IWYU pragma: keep

namespace fcppt::parse::skipper
{
/**
\brief Skips all characters from #fcppt::parse::space_set.
\ingroup fcpptparse
*/
template <typename Ch>
inline auto basic_space()
{
  return *fcppt::parse::skipper::basic_char_set<Ch>{fcppt::parse::space_set<Ch>()};
}

}

#endif
