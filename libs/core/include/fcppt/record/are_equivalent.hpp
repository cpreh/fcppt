//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ARE_EQUIVALENT_HPP_INCLUDED
#define FCPPT_RECORD_ARE_EQUIVALENT_HPP_INCLUDED

#include <fcppt/brigand/set_symmetric_difference.hpp>
#include <fcppt/record/element_map.hpp>
#include <fcppt/record/label_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/all.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/functions/logical/and.hpp>
#include <brigand/sequences/set.hpp>
#include <brigand/types/args.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Tests if two records have the same element maps

\ingroup fcpptrecord
*/
template<
	typename Record1,
	typename Record2
>
using
are_equivalent
=
::brigand::and_<
	std::is_same<
		fcppt::brigand::set_symmetric_difference<
			fcppt::record::label_set<
				Record1
			>,
			fcppt::record::label_set<
				Record2
			>
		>,
		::brigand::set<>
	>,
	::brigand::all<
		fcppt::record::label_set<
			Record1
		>,
		std::is_same<
			::brigand::bind<
				::brigand::lookup,
				::brigand::pin<
					fcppt::record::element_map<
						Record1
					>
				>,
				::brigand::_1
			>,
			::brigand::bind<
				::brigand::lookup,
				::brigand::pin<
					fcppt::record::element_map<
						Record2
					>
				>,
				::brigand::_1
			>
		>
	>
>;

}
}

#endif
