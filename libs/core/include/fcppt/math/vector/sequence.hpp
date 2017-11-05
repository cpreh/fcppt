//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_SEQUENCE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_SEQUENCE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/sequence.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Sequence for a vector.

\ingroup fcpptmathvector

Uses \link fcppt::optional::sequence\endlink.
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
inline
fcppt::optional::object<
	fcppt::math::vector::static_<
		T,
		N
	>
>
sequence(
	fcppt::math::vector::object<
		fcppt::optional::object<
			T
		>,
		N,
		S
	> const &_value
)
{
	return
		fcppt::math::detail::sequence<
			fcppt::math::vector::static_<
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
