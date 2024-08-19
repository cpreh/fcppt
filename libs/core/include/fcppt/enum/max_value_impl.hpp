//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_MAX_VALUE_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_MAX_VALUE_IMPL_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_
{
/**
\brief Specialization point for max_value.

\ingroup fcpptenum
*/
template <typename Type>
struct max_value_impl
{
  using type = std::integral_constant<Type, Type::fcppt_maximum>;
};
}

#endif
