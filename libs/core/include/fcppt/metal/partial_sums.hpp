//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_PARTIAL_SUMS_HPP_INCLUDED
#define FCPPT_METAL_PARTIAL_SUMS_HPP_INCLUDED

#include <fcppt/metal/list_c.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/algorithms/fold.hpp>
#include <metal/functions/arithmetic/plus.hpp>
#include <metal/functions/lambda/bind.hpp>
#include <metal/sequences/back.hpp>
#include <metal/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{

/**
\brief Calculates a new sequence that consists of the sums of the old sequence.

\ingroup fcpptmetal

For the integral constants (c_1, ..., c_n) in \a Sequence, the resulting
sequence will consist of the values (0, c_1, c_1 + c_2, ..., c_1 + ... c_n)

\snippet metal/various.cpp metal_partial_sums

\tparam Sequence A metal::list of integral constant types.

\tparam IntType The integer type to use for the first zero.
*/
template<
	typename Sequence,
	typename IntType = int
>
using
partial_sums
=
::metal::accumulate<
	::metal::bind<
		::metal::push_back,
		::metal::_state,
		::metal::bind<
			::metal::plus,
			::metal::bind<
				::metal::back,
				::metal::_state
			>,
			::metal::_element
		>
	>,
	fcppt::metal::list_c<
		IntType,
		0
	>,
	Sequence
>;

}
}

#endif
