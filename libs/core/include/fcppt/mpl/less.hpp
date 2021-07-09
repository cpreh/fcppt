//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LESS_HPP_INCLUDED
#define FCPPT_MPL_LESS_HPP_INCLUDED

#include <fcppt/mpl/integral_concept.hpp>
#include <fcppt/mpl/integrals_compatible.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{
namespace detail
{
template <typename T1, typename T2>
struct less;
template <typename T, T V1, T V2>
struct less<std::integral_constant<T, V1>, std::integral_constant<T, V2>>
{
  using type = std::bool_constant<(V1 < V2)>;
};
}
/**
\brief Checks if one integral constant is less than another.
\ingroup fcpptmpl
Let <code>T1 = std::integral_constant<T,V_1></code> and
<code>T2 = std::integral_constant<T,V_2></code>.
Then the result is <code>std::bool_constant<(V1 < V2)></code>.
*/
template <fcppt::mpl::integral_concept T1, fcppt::mpl::integral_concept T2>
requires fcppt::mpl::integrals_compatible<T1, T2>
using less = typename fcppt::mpl::detail::less<T1, T2>::type;
}

#endif
