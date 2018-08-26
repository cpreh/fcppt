//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_LIST_C_HPP_INCLUDED
#define FCPPT_BRIGAND_LIST_C_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief A list of integral_constants.

\ingroup fcpptbrigand
*/
template<
	typename Type,
	Type... Values
>
using
list_c
=
::brigand::list<
	std::integral_constant<
		Type,
		Values
	>...
>;

}
}

#endif
