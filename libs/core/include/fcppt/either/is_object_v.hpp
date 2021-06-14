//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_IS_OBJECT_V_HPP_INCLUDED
#define FCPPT_EITHER_IS_OBJECT_V_HPP_INCLUDED

#include <fcppt/either/is_object.hpp>

namespace fcppt::either
{
/**
\brief Checks if a given type is an #fcppt::either::object.

\ingroup fcppteither
*/
template<typename T>
inline constexpr bool is_object_v = fcppt::either::is_object<T>::value;
}

#endif
