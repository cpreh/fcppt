//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CATCH_MAKE_MOVABLE_HPP_INCLUDED
#define FCPPT_CATCH_MAKE_MOVABLE_HPP_INCLUDED

#include <fcppt/catch/movable_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::catch_
{
template <typename Type>
inline fcppt::catch_::movable<std::remove_cvref_t<Type>> make_movable(Type &&_value)
{
  return fcppt::catch_::movable<std::remove_cvref_t<Type>>{
      std::forward<Type>(_value)};
}

}

#endif
