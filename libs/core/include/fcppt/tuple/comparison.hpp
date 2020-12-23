//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_COMPARISON_HPP_INCLUDED
#define FCPPT_TUPLE_COMPARISON_HPP_INCLUDED

#include <fcppt/tuple/object_impl.hpp>

namespace fcppt::tuple
{
template <typename... Types>
[[nodiscard]] bool inline
operator==(fcppt::tuple::object<Types...> const &a, fcppt::tuple::object<Types...> const &b)
{
  return a.impl() == b.impl();
}
}

#endif
