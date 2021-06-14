//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_IS_OBJECT_V_HPP_INCLUDED
#define FCPPT_OPTIONAL_IS_OBJECT_V_HPP_INCLUDED

#include <fcppt/optional/is_object.hpp>

namespace fcppt::optional
{
/**
\brief Checks if a given type is an #fcppt::optional::object.

\ingroup fcpptoptional
*/
template<typename T>
inline constexpr bool is_object_v = fcppt::optional::is_object<T>::value;
}

#endif
