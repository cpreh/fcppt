//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_FIND_ELEMENT_DEREF_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_FIND_ELEMENT_DEREF_HPP_INCLUDED

#include <fcppt/record/detail/find_element.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename Elements,
	typename Element
>
using
find_element_deref
=
typename
boost::mpl::deref<
	fcppt::record::detail::find_element<
		Elements,
		Element
	>
>::type;

}
}
}

#endif
