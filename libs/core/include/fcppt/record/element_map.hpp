//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ELEMENT_MAP_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_MAP_HPP_INCLUDED

#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/fold.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/insert.hpp>
#include <brigand/sequences/pair.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief A metafunction computing the element map of a record

\ingroup fcpptrecord

\tparam Record Must be an #fcppt::record::object.
*/
template<
	typename Record
>
using
element_map
=
::brigand::fold<
	fcppt::record::element_vector<
		Record
	>,
	::brigand::map<>,
	::brigand::bind<
		::brigand::insert,
		::brigand::_state,
		::brigand::bind<
			::brigand::pair,
			::brigand::bind<
				fcppt::record::element_to_label,
				::brigand::_element
			>,
			::brigand::bind<
				fcppt::record::element_to_type,
				::brigand::_element
			>
		>
	>
>;

}
}

#endif
