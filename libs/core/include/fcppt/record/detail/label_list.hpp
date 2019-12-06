//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_LABEL_LIST_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_LABEL_LIST_HPP_INCLUDED

#include <fcppt/record/element_to_label.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename ElementList
>
using
label_list
=
::metal::transform<
	::metal::lambda<
		fcppt::record::element_to_label
	>,
	ElementList
>;

}
}
}

#endif
