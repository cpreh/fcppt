//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TYPE_ISO_UNDECORATE_HPP_INCLUDED
#define FCPPT_TYPE_ISO_UNDECORATE_HPP_INCLUDED

#include <fcppt/type_iso/undecorated_type.hpp>
#include <fcppt/type_iso/detail/undecorate.hpp>

namespace fcppt
{
namespace type_iso
{
/**
\brief Undecorates a value

Undecorates \a _value by removing all (nested) type constructors.

\ingroup fcppttypeiso
*/
template <typename Type>
inline fcppt::type_iso::undecorated_type<Type> undecorate(Type const &_value)
{
  return fcppt::type_iso::detail::undecorate(_value);
}

}
}

#endif
