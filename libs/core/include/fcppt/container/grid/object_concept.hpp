//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_OBJECT_CONCEPT_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OBJECT_CONCEPT_HPP_INCLUDED

#include <fcppt/container/grid/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::grid
{
/**
\brief Checks if a type is a cv-ref grid.

\ingroup fcpptcontainergrid
*/
template<typename Type>
concept object_concept = fcppt::container::grid::is_object<std::remove_cvref_t<Type>>::value;
}

#endif
