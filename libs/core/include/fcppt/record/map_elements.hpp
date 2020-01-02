//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_MAP_ELEMENTS_HPP_INCLUDED
#define FCPPT_RECORD_MAP_ELEMENTS_HPP_INCLUDED

#include <fcppt/record/element.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/record/from_list.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Maps the elements of a vector using a metafunction.

\ingroup fcpptrecord

\tparam Record Must be an #fcppt::record::object.

\tparam Function A metafunction accepting #fcppt::record::element
as parameter and returning the new mapped type.
*/
template<
	typename Record,
	typename Function
>
using
map_elements
=
fcppt::record::from_list<
	::metal::transform<
		::metal::bind<
			::metal::lambda<
				fcppt::record::element
			>,
			::metal::bind<
				::metal::lambda<
					fcppt::record::element_to_label
				>,
				::metal::_1
			>,
			Function
		>,
		fcppt::record::element_vector<
			Record
		>
	>
>;

}
}

#endif
