//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_LABEL_VALUE_TYPE_HPP_INCLUDED
#define FCPPT_RECORD_LABEL_VALUE_TYPE_HPP_INCLUDED

#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/detail/find_element_deref.hpp>


namespace fcppt
{
namespace record
{

template<
	typename Record,
	typename Label
>
using label_value_type
=
fcppt::record::element_to_type<
	fcppt::record::detail::find_element_deref<
		typename
		Record::all_types,
		Label
	>
>;

}
}

#endif
