//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_MAX_VALUE_IMPL_FWD_HPP_INCLUDED
#define FCPPT_ENUM_MAX_VALUE_IMPL_FWD_HPP_INCLUDED

namespace fcppt::enum_
{
/**
\brief Specialization point for max_value.

\ingroup fcpptenum

Has to contain a type called <code>type</code> of the form
<code>std::integral_constant<Type,max_value></code>, e.g.
\code
  using type = std::integral_constant<Type, max_value>;
\endcode
*/
template <typename Type>
struct max_value_impl;
}

#endif
