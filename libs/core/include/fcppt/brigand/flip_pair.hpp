//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_FLIP_PAIR_HPP_INCLUDED
#define FCPPT_BRIGAND_FLIP_PAIR_HPP_INCLUDED

#include <fcppt/brigand/pair_first.hpp>
#include <fcppt/brigand/pair_second.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/pair.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Flips a brigand pair.

\ingroup fcpptbrigand

Swaps first and second of \a Pair.

\tparam Pair Must be a brigand pair.
*/
template<
	typename Pair
>
using
flip_pair
=
::brigand::pair<
	fcppt::brigand::pair_second<
		Pair
	>,
	fcppt::brigand::pair_first<
		Pair
	>
>;

}
}

#endif
