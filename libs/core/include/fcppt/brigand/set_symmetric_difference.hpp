//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_SET_SYMMETRIC_DIFFERENCE_HPP_INCLUDED
#define FCPPT_BRIGAND_SET_SYMMETRIC_DIFFERENCE_HPP_INCLUDED

#include <fcppt/brigand/set_difference.hpp>
#include <fcppt/brigand/set_union.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief The symmetric difference of two sets.

\ingroup fcpptbrigand

The result contains every element that is either in \a Set1 or in \a Set2, but
not in both.

\tparam Set1 Must be a brigand set.
\tparam Set2 Must be a brigand set.
*/
template<
	typename Set1,
	typename Set2
>
using
set_symmetric_difference
=
fcppt::brigand::set_union<
	fcppt::brigand::set_difference<
		Set1,
		Set2
	>,
	fcppt::brigand::set_difference<
		Set2,
		Set1
	>
>;

}
}

#endif
