//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_SIZE_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_SIZE_HPP_INCLUDED

#include <fcppt/container/array/detail/size.hpp>


namespace fcppt
{
namespace container
{
namespace array
{

/**
\brief Gets the size of an array.

\ingroup fcpptcontainerarray

Derives from an integral constant that contains the size of \a Array.

\tparam Array Must be a <code>std::array</code>
*/
template<
	typename Array
>
using size
=
typename
fcppt::container::array::detail::size<
	Array
>::type;

}
}
}

#endif
