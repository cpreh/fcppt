//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_INIT_HPP_INCLUDED
#define FCPPT_TUPLE_INIT_HPP_INCLUDED

#include <fcppt/tuple/is_object.hpp>
#include <fcppt/tuple/size.hpp>
#include <fcppt/tuple/detail/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief Constructs a tuple by calling a function with static indices.

\ingroup fcppttuple

Constructs a tuple of type \a Tuple by calling
<code>_function(std::integral_constant<std::size_t, Index>)</code> for every index.

\tparam Tuple Must be an <code>fcppt::tuple::object</code>.

\tparam Function Must be a function callable as <code>T_i
(std::integral_constant<std::size_t, i>)</code> for <code>1 <= i <= n</code>,
where <code>Tuple=(T_1,...,T_n)</code>.
*/
template <
    typename Tuple,
    typename Function,
    typename = std::enable_if_t<fcppt::tuple::is_object<Tuple>::value>>
[[nodiscard]] inline Tuple init(Function const &_function)
{
  return fcppt::tuple::detail::init<Tuple>(
      std::make_index_sequence<fcppt::tuple::size<Tuple>::value>{}, _function);
}
}

#endif
