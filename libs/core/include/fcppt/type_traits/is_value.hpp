//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_VALUE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_VALUE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Checks if the type behaves like a value type.

\ingroup fcppttypetraits

A type is a <em>value type</em> if it is not cv-qualified, it is not void, not
an array, not a function and not a reference. In essence, value types behave
normally regarding copying, moving and assignment.
*/
template<
	typename Type
>
using is_value
=
std::integral_constant<
	bool,
	!std::is_void<
		Type
	>::value
	&&
	!std::is_array<
		Type
	>::value
	&&
	!std::is_function<
		Type
	>::value
	&&
	!std::is_reference<
		Type
	>::value
	&&
	!std::is_const<
		Type
	>::value
	&&
	!std::is_volatile<
		Type
	>::value
>;

}
}

#endif
