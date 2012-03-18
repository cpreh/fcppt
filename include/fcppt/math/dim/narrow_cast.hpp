//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_NARROW_CAST_HPP_INCLUDED
#define FCPPT_MATH_DIM_NARROW_CAST_HPP_INCLUDED

#include <fcppt/math/detail/narrow_cast.hpp>
#include <fcppt/math/dim/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Shortens a dim to a smaller dimension
\ingroup fcpptmathdim
\tparam Dest Must be a dim with a smaller dimension
\tparam N The dim's dimension
\tparam T The dim's <code>value_type</code>
\tparam S The dim's storage type
\param src The dim to shorten (narrow)

The inverse operation is fcppt::math::dim::construct.

\see fcppt::math::dim::construct

Example:

\code
typedef
fcppt::math::dim::static_<int,2>::type
int2;

typedef
fcppt::math::dim::static_<int,3>::type
int3;

int3 wide_dim(1,2,3);
int2 narrow_dim =
	fcppt::math::dim::narrow_cast<int2>(
		wide_dim);

// Outputs: 1,2
std::cout << narrow_dim;
\endcode
*/
template<
	typename Dest,
	typename T,
	typename N,
	typename S
>
Dest const
narrow_cast(
	object<T, N, S> const &src
)
{
	return math::detail::narrow_cast<
		Dest
	>(
		src
	);
}

}
}
}

#endif
