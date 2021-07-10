//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_OBJECT_CONCEPT_HPP_INCLUDED
#define FCPPT_MPL_MAP_OBJECT_CONCEPT_HPP_INCLUDED

#include <fcppt/mpl/map/is_object.hpp>

namespace fcppt::mpl::map
{

/**
\brief Concept for maps.
\ingroup fcpptmpl
\see fcppt::mpl::map::is_object
*/
template<typename T>
concept object_concept = fcppt::mpl::map::is_object<T>::value;

}

#endif
