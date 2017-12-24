//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_INTEGER_SEQUENCE_TO_TUPLE_HPP_INCLUDED
#define FCPPT_CONTAINER_INTEGER_SEQUENCE_TO_TUPLE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Maps an integer_sequence into a tuple of integral constants.

\ingroup fcpptcontainer

<code>std::integer_sequence<T,i_1,...,i_n></code>
is mapped into <code>std::tuple<std::integral_constant<T,i_1>,...,std::integral_constant<T,i_n>></code>.
*/
template<
	typename Type
>
struct integer_sequence_to_tuple;

template<
	typename Type,
	Type... Ints
>
struct integer_sequence_to_tuple<
	std::integer_sequence<
		Type,
		Ints...
	>
>
{
	typedef
	std::tuple<
		std::integral_constant<
			Type,
			Ints
		>...
	>
	type;
};

}
}

#endif
