//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_UNIQUE_HPP_INCLUDED
#define FCPPT_BRIGAND_UNIQUE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <brigand/adapted/list.hpp>
#include <brigand/algorithms/fold.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/insert.hpp>
#include <brigand/sequences/set.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Removes duplicates from a sequence.

\ingroup fcpptrecord

\tparam Sequence Must be a brigand sequence.
*/
template<
	typename Sequence
>
using
unique
=
::brigand::as_list<
	::brigand::fold<
		Sequence,
		::brigand::set<>,
		::brigand::bind<
			::brigand::insert,
			::brigand::_state,
			::brigand::_element
		>
	>
>;

}
}

#endif
