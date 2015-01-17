//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_CONSTRUCT_HPP_INCLUDED
#define FCPPT_MATH_DIM_CONSTRUCT_HPP_INCLUDED

#include <fcppt/math/detail/construct.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/static.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Constructs a dim with dimension \p N+1 from a dim with dimension \p N
\ingroup fcpptmathdim
\tparam N Must be a static dimension
\tparam T The dim's <code>value_type</code>
\tparam S The dim's storage type
\param base The "narrow" dim
\param t The element to insert to "widen" \p _base

The inverse operation is fcppt::math::dim::narrow_cast.

\see fcppt::math::dim::narrow_cast

Example:

\code
typedef
fcppt::math::dim::static_<int,2>
int2;

typedef
fcppt::math::dim::static_<int,3>
int3;

int2 narrow_dim(1,2);
int3 wide_dim =
	fcppt::math::dim::construct(
		narrow_dim,
		3);

// Outputs: 1,2,3
std::cout << wide_dim;
\endcode
*/
template<
	typename T,
	typename N,
	typename S
>
typename
fcppt::math::dim::static_<
	T,
	N::value + 1
> const
construct(
	fcppt::math::dim::object<
		T,
		N,
		S
	> const &base,
	T const &t
)
{
	return
		fcppt::math::detail::construct<
			typename
			fcppt::math::dim::static_<
				T,
				N::value + 1
			>
		>(
			base,
			t
		);
}

}
}
}

#endif
