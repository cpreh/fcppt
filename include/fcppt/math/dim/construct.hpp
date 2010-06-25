//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_CONSTRUCT_HPP_INCLUDED
#define FCPPT_MATH_DIM_CONSTRUCT_HPP_INCLUDED

#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/detail/construct.hpp>
#include <fcppt/math/is_static_size.hpp>

namespace fcppt
{
namespace math
{
namespace dim
{

/// Constructs a dim with dimension @a N+1 from a dim with dimension @a N
/**
 *  @tparam N must be a static dimension
*/
template<
	typename T,
	typename N,
	typename S
>
typename boost::enable_if<
	math::is_static_size<
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
	return
		math::detail::construct<
			typename static_<
				T,
				N::value + 1
			>::type
		>(
			base,
			t
		);
}

}
}
}

#endif
