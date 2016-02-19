//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_FILL_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_FILL_HPP_INCLUDED

#include <fcppt/math/detail/fill.hpp>
#include <fcppt/math/vector/is_vector.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Constructs a static vector with all components set to a given value

\ingroup fcpptmathvector

\tparam Vector Must be a vector

\param _value The value to fill the vector with
*/
template<
	typename Vector
>
Vector
fill(
	typename Vector::value_type const &_value
)
{
	static_assert(
		fcppt::math::vector::is_vector<
			Vector
		>::value,
		"Vector must be a vector"
	);

	return
		fcppt::math::detail::fill<
			Vector
		>(
			_value
		);
}

}
}
}

#endif
