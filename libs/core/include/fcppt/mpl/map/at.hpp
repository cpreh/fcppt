//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_MAP_AT_HPP_INCLUDED
#define FCPPT_MPL_MAP_AT_HPP_INCLUDED

#include <fcppt/mpl/map/element.hpp>
#include <fcppt/mpl/map/has_key.hpp>
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
template <typename... Elements>
struct table : Elements... // NOLINT(fuchsia-multiple-inheritance)
{
};

template <typename Key, typename Value>
Value lookup(fcppt::mpl::map::element<Key, Value> const &);
template <typename>
void lookup(...);
}
template <typename Map, typename Key>
struct at;

template<typename... Elements, typename Key>
struct at<fcppt::mpl::map::object<Elements...>,Key>
{
  using type = decltype(at_impl::lookup<Key>(std::declval<at_impl::table<Elements...>>()));
};
}
template<fcppt::mpl::map::object_concept Map, typename Key>
requires fcppt::mpl::map::has_key<Map,Key>::value
using at = typename fcppt::mpl::map::detail::at<Map,Key>::type;

}

#endif
