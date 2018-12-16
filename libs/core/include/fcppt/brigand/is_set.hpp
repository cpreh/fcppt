//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_IS_SET_HPP_INCLUDED
#define FCPPT_BRIGAND_IS_SET_HPP_INCLUDED

#include <fcppt/brigand/detail/is_set.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Checks if a sequence does not contain a type multiple times

\ingroup fcpptbrigand

\tparam Sequence A brigand sequence.
*/
template<
	typename Sequence
>
using
is_set
=
typename
fcppt::brigand::detail::is_set<
	Sequence
>::type;

}
}

#endif
