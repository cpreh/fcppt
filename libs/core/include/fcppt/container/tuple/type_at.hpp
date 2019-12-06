//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_TYPE_AT_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_TYPE_AT_HPP_INCLUDED

#include <fcppt/cast/size.hpp>
#include <fcppt/container/tuple/types_of.hpp>
#include <fcppt/metal/to_number.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <metal.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tuple
{

/**
\brief The type of the tuple element at a given position.

\ingroup fcpptcontainertuple

\tparam Tuple Must be a <code>std::tuple</code>.
*/
template<
	typename Tuple,
	std::size_t Index
>
using
type_at
=
::metal::at<
	fcppt::container::tuple::types_of<
		Tuple
	>,
	fcppt::metal::to_number<
		std::integral_constant<
			std::size_t,
			Index
		>
	>
>;

}
}
}

#endif
