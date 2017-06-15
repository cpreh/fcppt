//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_NARROW_CAST_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_NARROW_CAST_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
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

\param _src The vector to shorten (narrow)

The inverse operation is fcppt::math::vector::construct.

\see fcppt::math::vector::construct
*/
template<
	typename Dest,
	typename T,
	fcppt::math::size_type N,
	typename S
>
inline
Dest
narrow_cast(
	fcppt::math::vector::object<
		T,
		N,
		S
	> const &_src
)
{
	return
		fcppt::math::detail::narrow_cast<
			Dest
		>(
			_src
		);
}

}
}
}

#endif
