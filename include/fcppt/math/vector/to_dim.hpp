//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_TO_DIM_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_TO_DIM_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/to_different.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Converts a vector into a corresponding dim

\ingroup fcpptmathvector
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
inline
fcppt::math::dim::static_<
	T,
	N
>
to_dim(
	fcppt::math::vector::object<
		T,
		N,
		S
	> const &_src
)
{
	return
		fcppt::math::detail::to_different<
			fcppt::math::dim::static_<
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
