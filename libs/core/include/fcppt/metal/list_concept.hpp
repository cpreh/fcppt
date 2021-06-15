//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_LIST_CONCEPT_HPP_INCLUDED
#define FCPPT_METAL_LIST_CONCEPT_HPP_INCLUDED

#include <fcppt/metal/from_number.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt::metal
{

/**
\brief Concept for ::metal::list.

\ingroup fcpptmetal
*/
template<typename Type>
concept list_concept = fcppt::metal::from_number<bool,::metal::is_list<Type>>::value;

}

#endif
