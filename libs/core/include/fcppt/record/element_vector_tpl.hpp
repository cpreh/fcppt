//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ELEMENT_VECTOR_TPL_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_VECTOR_TPL_HPP_INCLUDED

#include <fcppt/record/is_object.hpp>


namespace fcppt
{
namespace record
{

/**
\brief A metafunction returning the elements of record as an MPL vector.

\ingroup fcpptrecord

\tparam Record Must be an \link fcppt::record::object\endlink.
*/
template<
	typename Record
>
struct element_vector_tpl
{
	static_assert(
		fcppt::record::is_object<
			Record
		>::value,
		"Record must be an fcppt::record::object"
	);

	typedef
	typename
	Record::all_types
	type;
};

}
}

#endif
