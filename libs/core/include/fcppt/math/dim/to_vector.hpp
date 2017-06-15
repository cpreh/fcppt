//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_TO_VECTOR_HPP_INCLUDED
#define FCPPT_MATH_DIM_TO_VECTOR_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/to_different.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/**
\brief Converts a dim into a corresponding vector

\ingroup fcpptmathdim
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
inline
fcppt::math::vector::static_<
	T,
	N
>
to_vector(
	fcppt::math::dim::object<
		T,
		N,
		S
	> const &_src
)
{
	return
		fcppt::math::detail::to_different<
			fcppt::math::vector::static_<
				T,
				N
			>
		>(
			_src
		);
}

}
}
}

#endif
