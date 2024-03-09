//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_DYNAMIC_HPP_INCLUDED
#define FCPPT_CAST_DYNAMIC_HPP_INCLUDED

#include <fcppt/cast/detail/dynamic.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/type_traits/is_base_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::cast
{
/**
\brief Converts between references of related types using
<code>dynamic_cast</code>, returning an empty optional on failure

\ingroup fcpptcasts

Tries to cast \a _src to \a Dest using <code>dynamic_cast</code>. On failure,
an empty optional is returned. To catch more mistakes, \a Base must be a
base class of \a Derived. In case you need a cross cast, use #fcppt::cast::dynamic_cross.

Here is an example:

\snippet cast/dynamic.cpp dynamic

\tparam Derived The type to cast to. Can be cv-qualified. Must inherit from \a Base.

\tparam Base A cv-qualified non-reference type.

\see #fcppt::cast::dynamic_cross
*/
template <typename Derived, typename Base>
inline fcppt::optional::reference<Derived> dynamic(Base &_base) noexcept
  requires(fcppt::type_traits::is_base_of<std::remove_cv_t<Base>, std::remove_cv_t<Derived>>::value)
{
  return fcppt::cast::detail::dynamic<Derived>(_base);
}
}

#endif
