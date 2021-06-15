//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_GET_UNSAFE_HPP_INCLUDED
#define FCPPT_VARIANT_GET_UNSAFE_HPP_INCLUDED

#include <fcppt/variant/has_type_v.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/detail/get_unsafe.hpp>

namespace fcppt::variant
{
/**
\brief Free get_unsafe function.

\ingroup fcpptvariant

Equal to <code>%_object.get&lt;Type&gt;()</code>.

\see #fcppt::variant::object::get_unsafe
*/
template <typename Type, typename... Elements>
inline Type &get_unsafe(fcppt::variant::object<Elements...> &_object)
requires fcppt::variant::has_type_v<fcppt::variant::object<Elements...>,Type>
{
  return fcppt::variant::detail::get_unsafe<Type>(_object);
}

/**
\brief Free get_unsafe function.

\ingroup fcpptvariant

Equal to <code>%_object.get&lt;Type&gt;()</code>.

\see #fcppt::variant::object::get_unsafe
*/
template <typename Type, typename... Elements>
inline Type const &get_unsafe(fcppt::variant::object<Elements...> const &_object)
requires fcppt::variant::has_type_v<fcppt::variant::object<Elements...>,Type>
{
  return fcppt::variant::detail::get_unsafe<Type>(_object);
}

}

#endif
