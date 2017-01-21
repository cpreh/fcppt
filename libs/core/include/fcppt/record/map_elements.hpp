//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_MAP_ELEMENTS_HPP_INCLUDED
#define FCPPT_RECORD_MAP_ELEMENTS_HPP_INCLUDED

#include <fcppt/record/element.hpp>
#include <fcppt/record/element_to_label_tpl.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/bind.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform.hpp>
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
as parameters and returning the new mapped types.
*/
template<
	typename Record,
	typename Function
>
using
map_elements
=
fcppt::record::object<
	typename
	boost::mpl::transform<
		typename
		Record::all_types,
		fcppt::record::element<
			fcppt::record::element_to_label_tpl<
				boost::mpl::_1
			>,
			boost::mpl::bind<
				typename
				boost::mpl::lambda<
					Function
				>::type,
				boost::mpl::_1
			>
		>
	>::type
>;

}
}

#endif
