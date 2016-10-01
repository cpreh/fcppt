//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ELEMENT_TO_TYPE_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_TO_TYPE_HPP_INCLUDED

#include <fcppt/record/element_to_type_tpl.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Extracts the label of an element

\ingroup fcpptrecord

\tparam Element Must be an \link fcppt::record::element\endlink.
*/
template<
	typename Element
>
using
element_to_type
=
typename
fcppt::record::element_to_type_tpl<
	Element
>::type;

}
}

#endif
