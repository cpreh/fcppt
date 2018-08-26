//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ALL_DISJOINT_HPP_INCLUDED
#define FCPPT_RECORD_ALL_DISJOINT_HPP_INCLUDED

#include <fcppt/brigand/set_union.hpp>
#include <fcppt/record/label_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/adapted/list.hpp>
#include <brigand/algorithms/flatten.hpp>
#include <brigand/algorithms/fold.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/set.hpp>
#include <brigand/sequences/size.hpp>
#include <brigand/types/args.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Tests if multiple records have disjoint label sets

\ingroup fcpptrecord
*/
template<
	typename Records
>
using
all_disjoint
=
std::is_same<
	::brigand::size<
		::brigand::fold<
			Records,
			::brigand::set<>,
			::brigand::bind<
				fcppt::brigand::set_union,
				::brigand::bind<
					fcppt::record::label_set,
					::brigand::_element
				>,
				::brigand::_state
			>
		>
	>,
	::brigand::size<
		::brigand::flatten<
			::brigand::transform<
				Records,
				::brigand::bind<
					::brigand::as_list,
					::brigand::bind<
						fcppt::record::label_set,
						::brigand::_1
					>
				>
			>
		>
	>
>;

}
}

#endif
