//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_INIT_HPP_INCLUDED
#define FCPPT_MATH_DIM_INIT_HPP_INCLUDED

#include <fcppt/math/detail/init.hpp>
#include <fcppt/math/dim/is_dim.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Initializes a dim

\ingroup fcpptmathdim

Calls <code>_function</code> for every index of the dim.

\tparam Dim Must be a dim

\tparam Function Must be a function of type <code>Dim::value_type
(Dim::size_type)</code>
*/
template<
	typename Dim,
	typename Function
>
inline
Dim
init(
	Function const &_function
)
{
	static_assert(
		fcppt::math::dim::is_dim<
			Dim
		>::value,
		"Dim must be a dim"
	);

	return
		fcppt::math::detail::init<
			Dim
		>(
			_function
		);
}

}
}
}

#endif
