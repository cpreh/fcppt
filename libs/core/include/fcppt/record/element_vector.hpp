//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ELEMENT_VECTOR_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_VECTOR_HPP_INCLUDED

#include <fcppt/record/element_vector_tpl.hpp>


namespace fcppt
{
namespace record
{

/**
\brief The elements of record as an MPL vector.

\ingroup fcpptrecord

\tparam Record Must be an \link fcppt::record::object\endlink.
*/
template<
	typename Record
>
using
element_vector
=
typename
fcppt::record::element_vector_tpl<
	Record
>::type;

}
}

#endif
