//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_IS_QUADRATIC_HPP_INCLUDED
#define FCPPT_MATH_DIM_IS_QUADRATIC_HPP_INCLUDED

#include <fcppt/math/dim/object_impl.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Checks if all elements of the dim are the same
\ingroup fcpptmathdim
\tparam N The dim's dimension
\tparam T The dim's <code>value_type</code>
\tparam S The dim's storage type
\param r The dimension to check
*/
template<
	typename T,
	typename N,
	typename S
>
bool
is_quadratic(
	dim::object<T,N,S> const &r
)
{
	for(
		auto const &item : r
	)
		if(item != r[0])
			return false;
	return true;
}
}
}
}

#endif
