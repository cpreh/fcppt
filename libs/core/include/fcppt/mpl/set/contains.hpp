//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_CONTAINS_HPP_INCLUDED
#define FCPPT_MPL_SET_CONTAINS_HPP_INCLUDED

#include <fcppt/mpl/set/object_concept.hpp>
#include <fcppt/mpl/set/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::set
{
namespace detail
{
namespace has_key_impl
{
template<typename T>
struct base
{
};
template <typename... Keys>
struct table : base<Keys>...
{
};
}
template <typename Set, typename Key>
struct contains;

template<typename... Elements, typename Key>
struct contains<fcppt::mpl::set::object<Elements...>,Key>
{
  using type = std::is_base_of<has_key_impl::base<Key>, has_key_impl::table<Elements...>>;
};
}

template<fcppt::mpl::set::object_concept Set, typename Key>
using contains = typename fcppt::mpl::set::detail::contains<Set,Key>::type;

}

#endif
