//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_APPLY_HPP_INCLUDED
#define FCPPT_TUPLE_APPLY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/tuple/apply_result.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/init.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/tuple/size.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief Applies a function to each tuple of elements of multiple tuples and returns a
tuple containing the results.

\ingroup fcppttuple

Let <code>Tuples=(t_1,...,t_n)</code>, where <code>t_i = u_{i,1}, ..., u_{i,k}</code>.
Calculates <code>r_j = _function(u_{1,j}, ..., u_{n,j})</code> for every
<code>1 <= j <= k</code>.

\tparam Tuples Must be <code>fcppt::tuple::object</code>s.
**/
template <typename Function, typename... Tuples>
fcppt::tuple::apply_result<Function, Tuples...>
apply(Function const &_function, Tuples &&..._tuples)
{
  static_assert(
      std::conjunction_v<
          fcppt::tuple::is_object<fcppt::type_traits::remove_cv_ref_t<Tuples>>...>,
      "Tuples must all be fcppt::tuple::objects");

  static_assert(
      std::is_same_v<std::integral_constant<
          std::size_t,
          fcppt::tuple::size<fcppt::type_traits::remove_cv_ref_t<Tuples>>::value>...>,
      "All tuples must have the same size");

  return fcppt::tuple::init<fcppt::tuple::apply_result<Function, Tuples...>>(
      [&_function, &_tuples...](auto const _index) {
        return _function(fcppt::tuple::get<_index()>(fcppt::move_if_rvalue<Tuples>(_tuples))...);
      });
}

}

#endif
