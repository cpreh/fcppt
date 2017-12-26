//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_PARTIAL_SUMS_HPP_INCLUDED
#define FCPPT_BRIGAND_PARTIAL_SUMS_HPP_INCLUDED

#include <fcppt/brigand/list_c.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/fold.hpp>
#include <brigand/functions/arithmetic/plus.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/back.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Calculates a new sequence that consists of the sums of the old sequence

\ingroup fcpptbrigand

For the integral constantsn (c_1, ..., c_n) in \a Sequence, the resulting
sequence will consist of the values (0, c_1, c_1 + c_2, ..., c_1 + ... c_n)

\snippet brigand/various.cpp brigand_partial_sums

\tparam Sequence An BRIGAND sequence of integral constant types

\tparam IntType The integer type to use for the first zero
*/
template<
	typename Sequence,
	// brigand::plus<> converts its operands, so int is most conservative
	typename IntType = int
>
using
partial_sums
=
::brigand::fold<
	Sequence,
	fcppt::brigand::list_c<
		IntType,
		0
	>,
	::brigand::bind<
		::brigand::push_back,
		::brigand::_state,
		::brigand::bind<
			::brigand::plus,
			::brigand::bind<
				::brigand::back,
				::brigand::_state
			>,
			::brigand::_element
		>
	>
>;

}
}

#endif
