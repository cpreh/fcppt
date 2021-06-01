//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONCEPTS_MOVE_CONSTRUCTIBLE_HPP_INCLUDED
#define FCPPT_CONCEPTS_MOVE_CONSTRUCTIBLE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::concepts
{
/**
\brief Checks if a type can be move-constructed and is an object type.
\ingroup fcpptconcepts
*/
template <typename Type>
concept move_constructible =
    std::is_object_v<Type> &&
	std::is_move_constructible_v<Type>;
}

#endif
