//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_TRANSFORM_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_TRANSFORM_HPP_INCLUDED

#include <fcppt/math/detail/transform.hpp>
#include <fcppt/math/vector/basic_fwd.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

/// Transforms @a _src using @a _fun on each element
template<
	typename T,
	typename N,
	typename S,
	typename Fun
>
vector::basic<T, N, S> const
transform(
	vector::basic<T, N, S> const &_src,
	Fun const &_fun
)
{
	return
		math::detail::transform(
			_src,
			_fun
		);
}

}
}
}

#endif
