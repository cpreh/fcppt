//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_ELEMENT_CONCEPT_HPP_INCLUDED
#define FCPPT_MPL_MAP_ELEMENT_CONCEPT_HPP_INCLUDED

#include <fcppt/mpl/map/is_element.hpp>

namespace fcppt::mpl::map
{

template<typename T>
concept element_concept = fcppt::mpl::map::is_element<T>::value;

}

#endif
