//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_STRUCTURE_CAST_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_STRUCTURE_CAST_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/structure_cast.hpp>
#include <fcppt/math/vector/is_vector.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Converts a vector into a different vector of the same dimension

\ingroup fcpptmathvector

\tparam Dest The destination vector type (not its value type!)

\tparam Conv the converter to use for each element

\tparam N The source vector's dimension

\tparam T The source vector's <code>value_type</code>

\tparam S The source vector's storage type

\param _src The vector to cast

See the introduction to fcppt::math::vector::object for more information on this
function (and vector in general).
*/
template<
	typename Dest,
	typename Conv,
	typename T,
	fcppt::math::size_type N,
	typename S
>
inline
Dest
structure_cast(
	fcppt::math::vector::object<
		T,
		N,
		S
	> const &_src
)
{
	static_assert(
		fcppt::math::vector::is_vector<
			Dest
		>::value,
		"Dest must be a vector"
	);

	return
		fcppt::math::detail::structure_cast<
			Dest,
			Conv
		>(
			_src
		);
}

}
}
}

#endif
