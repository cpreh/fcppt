//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_SIZE_TYPE_HPP_INCLUDED
#define FCPPT_ENUM_SIZE_TYPE_HPP_INCLUDED

#include <fcppt/enum/size_type_impl.hpp>

namespace fcppt
{
namespace enum_
{
/**
\brief The size type used to count the number of enumerators in an enum

\ingroup fcpptenum

The size type used to count the number of enumerators in \a Type.

\tparam Type Must be an enum type
*/
template <typename Type>
using size_type = typename fcppt::enum_::size_type_impl<Type>::type;

}
}

#endif
