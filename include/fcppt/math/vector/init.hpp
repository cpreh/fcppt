//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_INIT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_INIT_HPP_INCLUDED

#include <fcppt/math/detail/init.hpp>
#include <fcppt/math/vector/is_vector.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Initializes a vector

\ingroup fcpptmathvector

Calls <code>_function</code> for every index of the vector.

\type Vector Must be a vector

\type Function Must be a function of type <code>Vector::value_type
(Vector::size_type)</code>
*/
template<
	typename Vector,
	typename Function
>
inline
Vector
init(
	Function const &_function
)
{
	static_assert(
		fcppt::math::vector::is_vector<
			Vector
		>::value,
		"Vector must be a vector"
	);

	return
		fcppt::math::detail::init<
			Vector
		>(
			_function
		);
}

}
}
}

#endif
