//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_INSERT_HPP_INCLUDED
#define FCPPT_MPL_SET_INSERT_HPP_INCLUDED

#include <fcppt/mpl/set/contains.hpp>
#include <fcppt/mpl/set/object_concept.hpp>
#include <fcppt/mpl/set/object.hpp>

namespace fcppt::mpl::set
{
namespace detail
{
template<typename Set, typename Key>
struct insert;

template<typename... Elements, typename Key>
struct insert<fcppt::mpl::set::object<Elements...>,Key>
{
  using type = fcppt::mpl::set::object<Elements...,Key>;
};
}
template<fcppt::mpl::set::object_concept Set, typename Key>
requires (!fcppt::mpl::set::contains<Set,Key>::value)
using insert = typename fcppt::mpl::set::detail::insert<Set,Key>::type;
}

#endif
