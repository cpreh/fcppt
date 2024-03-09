//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_STATIC_DOWNCAST_HPP_INCLUDED
#define FCPPT_CAST_STATIC_DOWNCAST_HPP_INCLUDED

#include <fcppt/type_traits/is_base_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::cast
{
/**
\brief Statically converts a reference to a base class to a reference to a
derived class

\ingroup fcpptcasts

Converts \a _source to the reference type specified by \a Derived. This cast is
unsafe and should only be used if the \a _source has a dynamic type which is a
subtype of \a Derived. Consider using #fcppt::cast::dynamic  instead.

Derived must be a reference to a class type derived from Base.

\tparam Derived The type to cast to. Must be a reference type. Must inherit from \a Base.

\tparam Base A cv-qualified non-reference type.
*/
template <typename Derived, typename Base>
inline Derived static_downcast(Base &_source) noexcept
  requires(
      std::is_reference_v<Derived> &&
      fcppt::type_traits::is_base_of<std::remove_cv_t<Base>, std::remove_cvref_t<Derived>>::value)
{
  return static_cast<Derived>(_source);
}
}

#endif
