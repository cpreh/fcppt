//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_FLIP_MAP_HPP_INCLUDED
#define FCPPT_BRIGAND_FLIP_MAP_HPP_INCLUDED

#include <fcppt/brigand/flip_pair.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Flips a brigand map.

\ingroup fcpptbrigand

For each element of \a Map, swaps the key and the value type.
For this to work, the mapped types of the map must all be different ypes.

\tparam Map A brigand map.
*/
template<
	typename Map
>
using
flip_map
=
::brigand::transform<
	Map,
	::brigand::bind<
		fcppt::brigand::flip_pair,
		::brigand::_1
	>
>;

}
}

#endif

