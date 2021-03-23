//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_PROMOTE_INT_HPP_INCLUDED
#define FCPPT_CAST_PROMOTE_INT_HPP_INCLUDED

#include <fcppt/cast/promote_int_type.hpp>

namespace fcppt
{
namespace cast
{
/**
\brief Promotes an integral type to int or unsigned int.

\ingroup fcpptcasts

\tparam Type Must be an integral type.
*/
template <typename Type>
inline constexpr fcppt::cast::promote_int_type<Type> promote_int(Type const &_value)
{
  return static_cast<fcppt::cast::promote_int_type<Type>>(_value);
}

}
}

#endif
