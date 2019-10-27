//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ARE_EQUIVALENT_HPP_INCLUDED
#define FCPPT_RECORD_ARE_EQUIVALENT_HPP_INCLUDED

#include <fcppt/metal/set/make.hpp>
#include <fcppt/metal/set/symmetric_difference.hpp>
#include <fcppt/metal/set/to_list.hpp>
#include <fcppt/record/element_map.hpp>
#include <fcppt/record/label_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/always.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/trait.hpp>
#include <metal/list/all_of.hpp>
#include <metal/map/at_key.hpp>
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
std::conjunction<
	std::is_same<
		fcppt::metal::set::symmetric_difference<
			fcppt::record::label_set<
				Record1
			>,
			fcppt::record::label_set<
				Record2
			>
		>,
		fcppt::metal::set::make<>
	>,
	::metal::all_of<
		fcppt::metal::set::to_list<
			fcppt::record::label_set<
				Record1
			>
		>,
		::metal::bind<
			::metal::trait<
				std::is_same
			>,
			::metal::bind<
				::metal::lambda<
					::metal::at_key
				>,
				::metal::always<
					fcppt::record::element_map<
						Record1
					>
				>,
				::metal::_1
			>,
			::metal::bind<
				::metal::lambda<
					::metal::at_key
				>,
				::metal::always<
					fcppt::record::element_map<
						Record2
					>
				>,
				::metal::_1
			>
		>
	>
>;

}
}

#endif
