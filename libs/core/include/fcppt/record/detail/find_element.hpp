//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_FIND_ELEMENT_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_FIND_ELEMENT_HPP_INCLUDED

#include <fcppt/record/element_to_label_tpl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename Elements,
	typename Label
>
using find_element
=
typename
boost::mpl::find_if<
	Elements,
	std::is_same<
		fcppt::record::element_to_label_tpl<
			boost::mpl::_1
		>,
		Label
	>
>::type;

}
}
}

#endif
