//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANDOM_DISTRIBUTION_BASE_TYPE_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_BASE_TYPE_HPP_INCLUDED

#include <fcppt/type_iso/undecorated_type.hpp>

namespace fcppt
{
namespace random
{
namespace distribution
{
/**
\brief Calculates the base type

\see fcppt::type_iso::undecorated_type
*/
template <typename Type>
using base_type = fcppt::type_iso::undecorated_type<Type>;

}
}
}

#endif
