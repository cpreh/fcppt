//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_ALL_OF_HPP_INCLUDED
#define FCPPT_BRIGAND_ALL_OF_HPP_INCLUDED

#include <fcppt/brigand/detail/all_of_impl.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Checks if a predicate is true for every element.

\ingroup fcpptbrigand

\tparam Sequence Must be a brigand sequence.

\tparam Predicate A unary predicate.
*/
template<
	typename Sequence,
	typename Predicate
>
using
all_of
=
typename
fcppt::brigand::detail::all_of_impl<
	Sequence,
	Predicate
>::type;

}
}

#endif
