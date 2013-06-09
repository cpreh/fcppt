//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_FILL_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_FILL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/fill.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Constructs a static vector with all components set to a given value
\ingroup fcpptmathvector
\tparam N Must be a static dimension
\tparam T The vector's <code>value_type</code>
\param _value The value to fill the vector with
*/
template<
	math::size_type N,
	typename T
>
typename fcppt::math::vector::static_<
	T,
	N
>::type
fill(
	T const &_value
)
{
	return
		fcppt::math::detail::fill<
			typename fcppt::math::vector::static_<
				T,
				N
			>::type
		>(
			_value
		);
}

}
}
}

#endif
