//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_VARIANT_COMPARISON_HPP_INCLUDED
#define FCPPT_VARIANT_COMPARISON_HPP_INCLUDED

#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <concepts>
#include <fcppt/config/external_end.hpp>

namespace fcppt::variant
{
/**
\brief Compares two variants for equality.

\ingroup fcpptvariant

Compares \a _left and \a _right for equality. The two variants are equal if they hold
the same type and the values compare equal. This function requires all possible
types of the variant to be equality comparable.
*/
template <typename... Types>
[[nodiscard]] bool operator==(
    fcppt::variant::object<Types...> const &_left, fcppt::variant::object<Types...> const &_right)
    requires (std::equality_comparable<Types> &&...)
{
  return _left.impl() == _right.impl();
}

/**
\brief Compares two variants for inequality.

\ingroup fcpptvariant

Compares \a _a and \a _b for inequality. Equal to <code>!(_a == _b)</code>.
This function requires all possible types of the variant to be equality
comparable.
*/
template <typename... Types>
[[nodiscard]] bool operator!=(
    fcppt::variant::object<Types...> const &_a, fcppt::variant::object<Types...> const &_b)
    requires (std::equality_comparable<Types> &&...)
{
  return !(_a == _b);
}

}

#endif
