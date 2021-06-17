//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_CONCEPT_HPP_INCLUDED
#define FCPPT_MPL_LIST_CONCEPT_HPP_INCLUDED

#include <fcppt/mpl/is_list.hpp>

namespace fcppt::mpl
{

template<typename T>
concept list_concept = fcppt::mpl::is_list<T>::value;

}

#endif
