//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_DIM_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/detail/structure_cast.hpp>
#include <fcppt/math/dim/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Converts a dim into a different dim of the same dimension using <code>static_cast</code>
\ingroup fcpptmathdim
\tparam Dest The destination dim type (not its value type!)
\tparam N The source dim's dimension
\tparam T The source dim's <code>value_type</code>
\tparam S The source dim's storage type
\param _src The dim to cast

See the introduction to fcppt::math::vector::object for more information on this
function (and dim/vector in general).
*/
template<
	typename Dest,
	typename T,
	typename N,
	typename S
>
Dest const
structure_cast(
	object<T, N, S> const &_src
)
{
	return math::detail::structure_cast<
		Dest
	>(
		_src
	);

}

}
}
}

#endif
