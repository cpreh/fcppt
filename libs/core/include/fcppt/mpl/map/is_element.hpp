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
namespace detail
{
template <typename T>
struct is_element
{
  using type = std::false_type;
};

template <typename... T>
struct is_element<fcppt::mpl::map::element<T...>>
{
  using type = std::true_type;
};
}
/**
\brief Checks if a type is a map element.
\ingroup fcpptmpl
<code>T</code> is a map element if an only if it is of the form
<code>fcppt::mpl::map::element<K,V></code> for some types <code>K, V</code>.
*/
template<typename T>
using is_element = typename fcppt::mpl::map::detail::is_element<T>::type;
}

#endif
