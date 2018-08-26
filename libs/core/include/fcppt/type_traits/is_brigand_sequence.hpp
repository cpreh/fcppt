//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_BRIGAND_SEQUENCE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_BRIGAND_SEQUENCE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Checks if an type is an brigand sequence.

\ingroup fcppttypetraits

Checks if \a Type is an brigand sequence.

\tparam Type Can be any type
*/
template<
	typename Type
>
struct is_brigand_sequence
:
std::false_type
{
};

template<
	typename... Types
>
struct is_brigand_sequence<
	::brigand::list<
		Types...
	>
>
:
std::true_type
{
};

}
}

#endif
