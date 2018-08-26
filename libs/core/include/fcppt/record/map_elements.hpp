//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_MAP_ELEMENTS_HPP_INCLUDED
#define FCPPT_RECORD_MAP_ELEMENTS_HPP_INCLUDED

#include <fcppt/record/element.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Maps the elements of a vector using a metafunction.

\ingroup fcpptrecord

\tparam Record Must be an \link fcppt::record::object\endlink.

\tparam Function A metafunction accepting \link fcppt::record::element\endlink
as parameter and returning the new mapped type.
*/
template<
	typename Record,
	typename Function
>
using
map_elements
=
fcppt::record::object<
	::brigand::transform<
		fcppt::record::element_vector<
			Record
		>,
		::brigand::bind<
			fcppt::record::element,
			::brigand::bind<
				fcppt::record::element_to_label,
				::brigand::_1
			>,
			Function
		>
	>
>;

}
}

#endif
