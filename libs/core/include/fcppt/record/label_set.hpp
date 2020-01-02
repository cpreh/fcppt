//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_LABEL_SET_HPP_INCLUDED
#define FCPPT_RECORD_LABEL_SET_HPP_INCLUDED

#include <fcppt/metal/set/from_list_relaxed.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/record/detail/label_list.hpp>


namespace fcppt
{
namespace record
{

/**
\brief The set of labels of a record.

\ingroup fcpptrecord

\tparam Record Must be an #fcppt::record::object.
*/
template<
	typename Record
>
using
label_set
=
fcppt::metal::set::from_list_relaxed<
	fcppt::record::detail::label_list<
		fcppt::record::element_vector<
			Record
		>
	>
>;

}
}

#endif
