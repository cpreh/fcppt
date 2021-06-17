//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_IS_LIST_HPP_INCLUDED
#define FCPPT_MPL_IS_LIST_HPP_INCLUDED

#include <fcppt/mpl/list_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{
template <typename T>
struct is_list : std::false_type
{
};

template <typename... T>
struct is_list<fcppt::mpl::list<T...>> : std::true_type
{
};
}

#endif
