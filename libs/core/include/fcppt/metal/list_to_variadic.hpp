//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_LIST_TO_VARIADIC_HPP_INCLUDED
#define FCPPT_METAL_LIST_TO_VARIADIC_HPP_INCLUDED

#include <fcppt/metal/detail/list_to_variadic.hpp>


namespace fcppt
{
namespace metal
{

/**
\brief Turns a metal::list into a different type.

\ingroup fcpptmetal

Let <code>List=metal::list<t_1,...,t_n></code>.
The result is <code>Type<t_1,...,t_n></code>.

\tparam List Must be a metal::list.
*/
template<
	template<
		typename ...
	> class Type,
	typename List
>
using
list_to_variadic
=
typename
fcppt::metal::detail::list_to_variadic<
	Type,
	List
>::type;

}
}

#endif
