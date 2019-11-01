//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_FIND_ELEMENT_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_FIND_ELEMENT_HPP_INCLUDED

#include <fcppt/record/detail/find_element_predicate.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/list/at.hpp>
#include <metal/list/find_if.hpp>
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
using
find_element
=
::metal::at<
	Elements,
	::metal::find_if<
		Elements,
		fcppt::record::detail::find_element_predicate<
			Label
		>
	>
>;

}
}
}

#endif
