//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_AT_HPP_INCLUDED
#define FCPPT_MPL_MAP_AT_HPP_INCLUDED

#include <fcppt/mpl/map/element.hpp>
#include <fcppt/mpl/map/object_concept.hpp>
#include <fcppt/mpl/map/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::map
{
namespace detail
{
namespace at_impl
{
template <typename Map>
struct table
{
};

template <typename... Elements>
struct table<fcppt::mpl::map::object<Elements...>> : Elements...
{
};

template <typename Key, typename Value>
Value lookup(fcppt::mpl::map::element<Key, Value> const &);
template <typename>
void lookup(...);
}
template <typename Map, typename Key>
using at = decltype(at_impl::lookup<Key>(std::declval<at_impl::table<Map>>()));
}
template<fcppt::mpl::map::object_concept Map, typename Key>
using at = fcppt::mpl::map::detail::at<Map,Key>;

}

#endif
