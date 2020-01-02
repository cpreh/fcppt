//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TUPLE_TYPES_OF_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_TYPES_OF_HPP_INCLUDED

#include <fcppt/container/tuple/detail/types_of.hpp>


namespace fcppt
{
namespace container
{
namespace tuple
{

/**
\brief The types of a tuple as a metal::list.

\ingroup fcpptcontainertuple

\tparam Tuple Must be a <code>std::tuple</code>.
*/
template<
	typename Tuple
>
using
types_of
=
typename
fcppt::container::tuple::detail::types_of<
	Tuple
>::type;

}
}
}

#endif
