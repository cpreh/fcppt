//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_HAS_KEY_HPP_INCLUDED
#define FCPPT_MPL_MAP_HAS_KEY_HPP_INCLUDED

#include <fcppt/mpl/map/element_key.hpp>
#include <fcppt/mpl/map/object_concept.hpp>
#include <fcppt/mpl/map/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::map
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
template <typename Map, typename Key>
struct has_key;

template<typename... Elements, typename Key>
struct has_key<fcppt::mpl::map::object<Elements...>,Key>
{
  using type = std::is_base_of<
      has_key_impl::base<Key>,
      has_key_impl::table<fcppt::mpl::map::element_key<Elements>...>>;
};
}

template<fcppt::mpl::map::object_concept Map, typename Key>
using has_key = typename fcppt::mpl::map::detail::has_key<Map,Key>::type;

}

#endif
