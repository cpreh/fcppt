//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ELEMENT_TAG_TUPLE_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_TAG_TUPLE_HPP_INCLUDED

#include <fcppt/record/element_tag_tuple_tpl.hpp>


namespace fcppt
{
namespace record
{

/**
\brief The elements of record as a <code>std::tuple</code> of <code>fcppt::tag</code> types.

\ingroup fcpptrecord

\tparam Record Must be an \link fcppt::record::object\endlink.
*/
template<
	typename Record
>
using
element_tag_tuple
=
typename
fcppt::record::element_tag_tuple_tpl<
	Record
>::type;

}
}

#endif
