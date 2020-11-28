//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_PROMOTE_INT_TYPE_HPP_INCLUDED
#define FCPPT_CAST_PROMOTE_INT_TYPE_HPP_INCLUDED

#include <fcppt/cast/detail/promote_int_type.hpp>

namespace fcppt
{
namespace cast
{
/**
\brief The promoted type of an integral  type.

\ingroup fcpptcasts

\tparam Type Must be an integral type.
*/
template <typename Type>
using promote_int_type = typename fcppt::cast::detail::promote_int_type<Type>::type;

}
}

#endif
