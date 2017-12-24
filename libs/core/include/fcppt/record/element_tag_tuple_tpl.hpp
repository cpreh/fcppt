//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ELEMENT_TAG_TUPLE_TPL_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_TAG_TUPLE_TPL_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/mpl/sequence_to_tuple.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/record/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

template<
	typename Record
>
struct element_tag_tuple_tpl
:
fcppt::mpl::sequence_to_tuple<
	typename
	boost::mpl::transform<
		fcppt::record::element_vector<
			Record
		>,
		fcppt::tag<
			boost::mpl::_1
		>
	>::type
>
{
	static_assert(
		fcppt::record::is_object<
			Record
		>::value,
		"Record must be an fcppt::record::object"
	);
};

}
}

#endif
