//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_IS_OBJECT_V_HPP_INCLUDED
#define FCPPT_VARIANT_IS_OBJECT_V_HPP_INCLUDED

#include <fcppt/variant/is_object.hpp>

namespace fcppt::variant
{
/**
\brief Checks if a given type is an #fcppt::variant::object.

\ingroup fcpptvariant
*/
template<typename T>
inline constexpr bool is_object_v = fcppt::variant::is_object<T>::value;
}

#endif
