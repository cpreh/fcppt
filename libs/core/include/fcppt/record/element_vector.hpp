//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ELEMENT_VECTOR_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_VECTOR_HPP_INCLUDED

#include <fcppt/record/detail/element_vector.hpp>


namespace fcppt
{
namespace record
{

/**
\brief A metafunction returning the elements of record as an MPL vector.

\ingroup fcpptrecord

\tparam Record Must be an #fcppt::record::object.
*/
template<
	typename Record
>
using
element_vector
=
typename
fcppt::record::detail::element_vector<
	Record
>::type;

}
}

#endif
