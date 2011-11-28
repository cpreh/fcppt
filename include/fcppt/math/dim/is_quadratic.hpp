//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_IS_QUADRATIC_HPP_INCLUDED
#define FCPPT_MATH_DIM_IS_QUADRATIC_HPP_INCLUDED

#include <fcppt/math/dim/basic_impl.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/// Checks if all dimensions of @a r are the same
template<
	typename T,
	typename N,
	typename S
>
bool
is_quadratic(
	dim::basic<T,N,S> const &r
)
{
	for(
		typename dim::basic<T,N,S>::const_iterator i = r.begin();
		i != r.end();
		++i
	)
		if(*i != r[0])
			return false;
	return true;
}
}
}
}

#endif
