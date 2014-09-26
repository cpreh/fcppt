//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_FILL_HPP_INCLUDED
#define FCPPT_MATH_DIM_FILL_HPP_INCLUDED

#include <fcppt/math/detail/fill.hpp>
#include <fcppt/math/dim/is_dim.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Constructs a static dim with all components set to a given value
\ingroup fcpptmathdim
\tparam Dim Must be a dim
\param _value The value to fill the dim with
*/
template<
	typename Dim
>
Dim
fill(
	typename Dim::value_type const &_value
)
{
	static_assert(
		fcppt::math::dim::is_dim<
			Dim
		>::value,
		"Dim must be a dim"
	);

	return
		fcppt::math::detail::fill<
			Dim
		>(
			_value
		);
}

}
}
}

#endif
