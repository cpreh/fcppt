//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_IS_ELEMENT_HPP_INCLUDED
#define FCPPT_MPL_MAP_IS_ELEMENT_HPP_INCLUDED

#include <fcppt/mpl/map/element_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::map
{
template <typename T>
struct is_element : std::false_type
{
};

template <typename... T>
struct is_element<fcppt::mpl::map::element<T...>> : std::true_type
{
};
}

#endif
