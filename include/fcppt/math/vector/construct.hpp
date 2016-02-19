//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_CONSTRUCT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_CONSTRUCT_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/construct.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Constructs a vector with dimension \p N+1 from a vector with dimension
\p N

\ingroup fcpptmathvector

\param _base The "narrow" vector

\param _t The element to insert to "widen" \p _base

The inverse operation is fcppt::math::vector::narrow_cast.

\see fcppt::math::vector::narrow_cast
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
fcppt::math::vector::static_<
	T,
	N + 1
>
construct(
	fcppt::math::vector::object<
		T,
		N,
		S
	> const &_base,
	T const &_t
)
{
	return
		fcppt::math::detail::construct<
			fcppt::math::vector::static_<
				T,
				N + 1
			>
		>(
			_base,
			_t
		);
}

}
}
}

#endif
