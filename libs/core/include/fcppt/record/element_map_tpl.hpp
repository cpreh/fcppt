//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ELEMENT_MAP_TPL_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_MAP_TPL_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element_to_label_tpl.hpp>
#include <fcppt/record/element_to_type_tpl.hpp>
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

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
	typename
	Record::all_types,
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

FCPPT_PP_POP_WARNING

}
}

#endif
