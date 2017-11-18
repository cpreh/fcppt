//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_ITERABLE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_ITERABLE_HPP_INCLUDED

#include <fcppt/type_traits/has_const_iterator.hpp>
#include <fcppt/type_traits/has_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Checks if a type has iterator typedefs

\ingroup fcppttypetraits

Checks if \a Type has iterator typedefs. If \a Type is const, then it checked
for a <code>const_iterator</code> typedef. Otherwise, it is checked for an
<code>iterator</code> typedef.

\tparam Type Can be any type
*/
template<
	typename Type
>
using is_iterable
=
typename
std::conditional<
	std::is_const<
		Type
	>::value,
	fcppt::type_traits::has_const_iterator<
		Type
	>,
	fcppt::type_traits::has_iterator<
		Type
	>
>::type;

}
}

#endif
