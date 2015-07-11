//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_RANGE_ELEMENT_TYPE_HPP_INCLUDED
#define FCPPT_ALGORITHM_RANGE_ELEMENT_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief The type of a range element

\ingroup fcpptalgorithm

Depending on the range, this can be a reference, const reference or an object
type.
*/
template<
	typename Range
>
using
range_element_type
=
decltype(
	*std::declval<
		Range
	>().begin()
);

}
}

#endif
