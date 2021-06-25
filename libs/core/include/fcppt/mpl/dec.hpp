//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_DEC_HPP_INCLUDED
#define FCPPT_MPL_DEC_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/mpl/integral_concept.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{
namespace detail
{
template<typename T>
struct dec;
template<typename T, T V>
struct dec<std::integral_constant<T,V>>
{
  using type = std::integral_constant<T,V - fcppt::literal<T>(1)>;
};
}
template <fcppt::mpl::integral_concept T>
using dec = typename fcppt::mpl::detail::dec<T>::type;
}

#endif
