//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_TYPE_AT_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_TYPE_AT_HPP_INCLUDED

#include <fcppt/cast/size.hpp>
#include <fcppt/container/tuple/types_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/at.hpp>
#include <cstddef>
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
::brigand::at_c<
	fcppt::container::tuple::types_of<
		Tuple
	>,
	fcppt::cast::size<
		unsigned int
	>(
		Index
	)
>;

}
}
}

#endif