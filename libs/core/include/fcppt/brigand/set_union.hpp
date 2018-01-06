//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_SET_UNION_HPP_INCLUDED
#define FCPPT_BRIGAND_SET_UNION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/fold.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/insert.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief The union of two sets.

\ingroup fcpptbrigand

The result contains every element that is in \a Set1 or in \a Set2.

\tparam Set1 Must be a brigand set.

\tparam Set2 Must be a brigand set.
*/
template<
	typename Set1,
	typename Set2
>
using set_union
=
::brigand::fold<
	Set1,
	Set2,
	::brigand::bind<
		::brigand::insert,
		::brigand::_state,
		::brigand::_element
	>
>;

}
}

#endif
