//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_RANGE_HPP_INCLUDED
#define FCPPT_ALGORITHM_RANGE_HPP_INCLUDED

#include <fcppt/mpl/list/is_object.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ranges>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
/**
\brief Checks if a type is an input range or an mpl list.
\ingroup fcpptalgorithm
*/
template <typename Type>
concept range = std::ranges::input_range<Type> || fcppt::mpl::list::is_object<Type>::value ||
                fcppt::tuple::is_object<Type>::value;
}

#endif
