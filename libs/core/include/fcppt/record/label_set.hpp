//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_LABEL_SET_HPP_INCLUDED
#define FCPPT_RECORD_LABEL_SET_HPP_INCLUDED

#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/fold.hpp>
#include <brigand/sequences/insert.hpp>
#include <brigand/sequences/set.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief The set of labels of a record.

\ingroup fcpptrecord

\tparam Record Must be an \link fcppt::record::object\endlink.
*/
template<
	typename Record
>
using
label_set
=
::brigand::fold<
	fcppt::record::element_vector<
		Record
	>,
	::brigand::set<>,
	::brigand::bind<
		::brigand::insert,
		::brigand::_state,
		::brigand::bind<
			fcppt::record::element_to_label,
			::brigand::_element
		>
	>
>;

}
}

#endif
