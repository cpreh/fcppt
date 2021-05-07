//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_MAKE_HPP_INCLUDED
#define FCPPT_TUPLE_MAKE_HPP_INCLUDED

#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
template <typename... Types>
[[nodiscard]] inline fcppt::tuple::object<std::remove_cvref_t<Types>...>
make(Types &&..._args)
{
  return fcppt::tuple::object<std::remove_cvref_t<Types>...>(
      std::forward<Types>(_args)...);
}
}

#endif
