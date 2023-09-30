//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_IS_SKIPPER_V_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_IS_SKIPPER_V_HPP_INCLUDED

#include <fcppt/parse/skipper/is_skipper.hpp>

namespace fcppt::parse::skipper
{
/**
\brief Checks if a type is a skipper.
\ingroup fcpptparse
\see fcppt::parse::skipper::is_skipper
*/
template <typename Type>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool is_skipper_v = fcppt::parse::skipper::is_skipper<Type>::value;

}

#endif
