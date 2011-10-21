//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_BEFORE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_BEFORE_HPP_INCLUDED

#include <fcppt/math/detail/before.hpp>
#include <fcppt/math/vector/basic_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename T,
	typename N,
	typename S
>
bool
before(
	basic<T, N, S> const &_a,
	basic<T, N, S> const &_b
)
{
	return
		math::detail::before(
			_a,
			_b
		);
}

}
}
}

#endif
