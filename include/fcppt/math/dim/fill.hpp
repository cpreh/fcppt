//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_FILL_HPP_INCLUDED
#define FCPPT_MATH_DIM_FILL_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/fill.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/static.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Constructs a static dim with all components set to a given value
\ingroup fcpptmathdim
\tparam N Must be a static dimension
\tparam T The dim's <code>value_type</code>
\param _value The value to fill the dim with
*/
template<
	math::size_type N,
	typename T
>
fcppt::math::dim::static_<
	T,
	N
>
fill(
	T const &_value
)
{
	return
		fcppt::math::detail::fill<
			fcppt::math::dim::static_<
				T,
				N
			>
		>(
			_value
		);
}

}
}
}

#endif
