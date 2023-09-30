//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONST_HPP_INCLUDED
#define FCPPT_CONST_HPP_INCLUDED

#include <fcppt/detail/const.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Function returning a constant

\ingroup fcpptvarious
*/
template <typename Type>
inline fcppt::detail::const_<Type> const_(Type _value)
{
  static_assert(!std::is_lvalue_reference_v<Type>, "Type must be a non-reference type");

  return fcppt::detail::const_<Type>(std::move(_value));
}

}

#endif
