//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_AS_STRUCT_HPP_INCLUDED
#define FCPPT_TUPLE_AS_STRUCT_HPP_INCLUDED

#include <fcppt/tuple/invoke.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief Converts a tuple to a struct.
\ingroup fcppttuple

\tparam Result Has to be constructible from the tuple's types, i.e.  if
<code>Tuple = (t_1,..,t_n)</code>, then <code>Result</code> has to be
constructible from <code>t_1, ..., t_n</code>.
TODO(philipp): concepts
*/
template <typename Result, typename Tuple>
[[nodiscard]] constexpr Result as_struct(Tuple &&_tuple)
  requires(fcppt::tuple::is_object<std::remove_cvref_t<Tuple>>::value)
{
  return fcppt::tuple::invoke(
      [](auto &&..._values) { return Result{std::forward<decltype(_values)>(_values)...}; },
      std::forward<Tuple>(_tuple));
}
}

#endif
