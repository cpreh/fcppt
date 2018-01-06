//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_MAX_VALUE_HPP_INCLUDED
#define FCPPT_BRIGAND_MAX_VALUE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/fold.hpp>
#include <brigand/functions/if.hpp>
#include <brigand/functions/comparison/greater.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/front.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Calculates the maximum value in a sequence.

\ingroup fcpptbrigand

Calculates the maximum value in \a Sequence.

\snippet brigand/various.cpp brigand_max_value

\tparam Sequence A non empty brigand sequence.
*/
template<
	typename Sequence
>
using
max_value
=
::brigand::fold<
	Sequence,
	::brigand::front<
		Sequence
	>,
	::brigand::if_<
		::brigand::bind<
			::brigand::greater,
			::brigand::_state,
			::brigand::_element
		>,
		::brigand::_state,
		::brigand::_element
	>
>;

}
}

#endif
