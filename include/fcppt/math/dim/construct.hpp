//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_CONSTRUCT_HPP_INCLUDED
#define FCPPT_MATH_DIM_CONSTRUCT_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/construct.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/static.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Constructs a dim with dimension \p N+1 from a dim with dimension \p N

\ingroup fcpptmathdim
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
inline
fcppt::math::dim::static_<
	T,
	N + 1u
>
construct(
	fcppt::math::dim::object<
		T,
		N,
		S
	> const &_dim,
	T const &_value
)
{
	return
		fcppt::math::detail::construct<
			fcppt::math::dim::static_<
				T,
				N + 1u
			>
		>(
			_dim,
			_value
		);
}

}
}
}

#endif
