//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ELEMENT_TAG_TUPLE_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_TAG_TUPLE_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/adapted/tuple.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief A metafunction returning the elements of record as a <code>std::tuple</code> of <code>fcppt::tag</code> types.

\ingroup fcpptrecord

\tparam Record Must be an \link fcppt::record::object\endlink.
*/
template<
	typename Record
>
using
element_tag_tuple
=
::brigand::as_tuple<
	::brigand::transform<
		fcppt::record::element_vector<
			Record
		>,
		::brigand::bind<
			fcppt::tag,
			::brigand::_1
		>
	>
>;

}
}

#endif
