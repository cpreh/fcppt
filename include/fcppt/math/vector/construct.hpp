//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_CONSTRUCT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_CONSTRUCT_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/detail/is_static_size.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

/// Constructs a vector with dimension @a N+1 from a vector with dimension @a N
/**
 *  @param N must be a static dimension
*/
template<
	typename T,
	typename N,
	typename S
>
typename boost::enable_if<
	math::detail::is_static_size<
		N
	>,
	typename static_<
		T,
		N::value + 1
	>::type
>::type const
construct(
	basic<T, N, S> const &base,
	T const &t
)
{
	typename static_<
		T,
		N::value + 1
	>::type ret;

	for(
		typename basic<T, N, S>::size_type i = 0;
		i < base.size();
		++i
	)
		ret[i] = base[i];

	ret[N::value] = t;

	return ret;
}

}
}
}

#endif
