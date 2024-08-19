//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_MAX_VALUE_HPP_INCLUDED
#define FCPPT_ENUM_MAX_VALUE_HPP_INCLUDED

#include <fcppt/enum/is_object.hpp>
#include <fcppt/enum/max_value_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::enum_
{
/**
\brief The maximum enumerator in an enum.

This class defines the maximum enumerator (the enumerator with the biggest
integral value) in the enum denoted by \a Type. The default behaviour is to use
<code>Type::fcppt_maximum</code>. Specialize <code>fcppt::enum_::max_value_impl</code> to change that.

\ingroup fcpptenum

\note Unfortunately, there is no way to automatically retrieve the maximum
enumerator in an enum in C++.

\tparam Type Must be an enum type.
*/
template <typename Type, typename = std::enable_if_t<fcppt::enum_::is_object<Type>::value>>
using max_value = typename fcppt::enum_::max_value_impl<Type>::type;

}

#endif
