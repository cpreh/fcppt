//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ELEMENT_MAP_TPL_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_MAP_TPL_HPP_INCLUDED

#include <fcppt/record/element_to_label_tpl.hpp>
#include <fcppt/record/element_to_type_tpl.hpp>
#include <fcppt/record/element_vector.hpp>
#include <fcppt/record/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/map/map10.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief A metafunction computing the element map of a record

\ingroup fcpptrecord

\tparam Record Must be an \link fcppt::record::object\endlink.
*/
template<
	typename Record
>
struct element_map_tpl
:
boost::mpl::fold<
	fcppt::record::element_vector<
		Record
	>,
	boost::mpl::map0<>,
	boost::mpl::insert<
		boost::mpl::_1,
		boost::mpl::pair<
			fcppt::record::element_to_label_tpl<
				boost::mpl::_2
			>,
			fcppt::record::element_to_type_tpl<
				boost::mpl::_2
			>
		>
	>
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
