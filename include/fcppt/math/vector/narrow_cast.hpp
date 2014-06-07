//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_NARROW_CAST_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_NARROW_CAST_HPP_INCLUDED

#include <fcppt/math/detail/narrow_cast.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Shortens a vector to a smaller dimension
\ingroup fcpptmathvector
\tparam Dest Must be a vector with a smaller dimension
\tparam N The vector's dimension
\tparam T The vector's <code>value_type</code>
\tparam S The vector's storage type
\param src The vector to shorten (narrow)

The inverse operation is fcppt::math::vector::construct.

\see fcppt::math::vector::construct

Example:

\code
typedef
fcppt::math::vector::static_<int,2>::type
int2;

typedef
fcppt::math::vector::static_<int,3>::type
int3;

int3 wide_vector(1,2,3);
int2 narrow_vector =
	fcppt::math::vector::narrow_cast<int2>(
		wide_vector);

// Outputs: 1,2
std::cout << narrow_vector;
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
	return
		math::detail::narrow_cast<
			Dest
		>(
			src
		);
}

}
}
}

#endif
