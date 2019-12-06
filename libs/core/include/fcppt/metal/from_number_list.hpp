//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_FROM_NUMBER_LIST_HPP_INCLUDED
#define FCPPT_METAL_FROM_NUMBER_LIST_HPP_INCLUDED

#include <fcppt/metal/from_number.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{

/**
\brief Converts a metal::list of metal::numbers into a metal::list of std::integral_constants.

\ingroup fcpptmetal

Applies <code>fcppt::metal::from_number<Result,_></code> to each element of the list.

\tparam Result Must be an integral type.

\tparam List Must be a metal::list of metal::numbers.
*/
template<
	typename Result,
	typename List
>
using
from_number_list
=
::metal::transform<
	::metal::bind<
		::metal::lambda<
			fcppt::metal::from_number
		>,
		::metal::always<
			Result
		>,
		::metal::_1
	>,
	List
>;

}
}

#endif
