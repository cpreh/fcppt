//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_FLIP_PAIR_HPP_INCLUDED
#define FCPPT_METAL_FLIP_PAIR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{

/**
\brief Flips a metal pair.

\ingroup fcpptmetal

Swaps first and second of \a Pair.

\tparam Pair Must be a metal::pair.
*/
template<
	typename Pair
>
using
flip_pair
=
::metal::pair<
	::metal::second<
		Pair
	>,
	::metal::first<
		Pair
	>
>;

}
}

#endif
