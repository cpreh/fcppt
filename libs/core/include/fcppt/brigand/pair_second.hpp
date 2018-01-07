//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_PAIR_SECOND_HPP_INCLUDED
#define FCPPT_BRIGAND_PAIR_SECOND_HPP_INCLUDED


namespace fcppt
{
namespace brigand
{

/**
\brief The second type of a pair.

\ingroup fcpptbrigand

\tparam Pair Must be a brigand::pair.
*/
template<
	typename Pair
>
using
pair_second
=
typename
Pair::second_type;

}
}

#endif
