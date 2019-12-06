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
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief A metafunction computing the element map of a record.

\ingroup fcpptrecord

\tparam Record Must be an #fcppt::record::object.
*/
template<
	typename Record
>
using
element_map
=
::metal::accumulate<
	::metal::bind<
		::metal::lambda<
			::metal::insert_key
		>,
		::metal::_1,
		::metal::bind<
			::metal::lambda<
				fcppt::record::element_to_label
			>,
			::metal::_2
		>,
		::metal::bind<
			::metal::lambda<
				fcppt::record::element_to_type
			>,
			::metal::_2
		>
	>,
	::metal::map<>,
	fcppt::record::element_vector<
		Record
	>
>;

}
}

#endif
