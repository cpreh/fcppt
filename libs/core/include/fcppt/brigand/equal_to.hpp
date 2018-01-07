//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_EQUAL_TO_HPP_INCLUDED
#define FCPPT_BRIGAND_EQUAL_TO_HPP_INCLUDED

#include <fcppt/brigand/all_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/functions/comparison/equal_to.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Checks if two sequences of integral constants are equal.

\ingroup fcpptbrigand

Checks if \a Sequence1 is equal to \a Sequence2. Both sequences must be a of
the same length.

\tparam Sequence1 A brigand sequence of integral constants.

\tparam Sequence2 A brigand sequence of integral constants.
*/
template<
	typename Sequence1,
	typename Sequence2
>
using
equal_to
=
fcppt::brigand::all_of<
	::brigand::transform<
		Sequence1,
		Sequence2,
		::brigand::bind<
			::brigand::equal_to,
			::brigand::_1,
			::brigand::_2
		>
	>,
	::brigand::_1
>;

}
}

#endif
