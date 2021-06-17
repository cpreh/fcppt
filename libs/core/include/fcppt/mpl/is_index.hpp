//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_IS_INDEX_HPP_INCLUDED
#define FCPPT_MPL_IS_INDEX_HPP_INCLUDED

#include <fcppt/mpl/index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{
template <typename T>
struct is_index : std::false_type
{
};

template <std::size_t I>
struct is_index<fcppt::mpl::index<I>> : std::true_type
{
};
}

#endif
