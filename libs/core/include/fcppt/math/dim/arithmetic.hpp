//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIM_ARITHMETIC_HPP_INCLUDED
#define FCPPT_MATH_DIM_ARITHMETIC_HPP_INCLUDED

#include <fcppt/math/div.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_map.hpp>
#include <fcppt/math/detail/make_asymmetric_binary_operator.hpp>
#include <fcppt/math/detail/make_asymmetric_binary_operator_right.hpp>
#include <fcppt/math/detail/make_symmetric_binary_operator.hpp>
#include <fcppt/math/detail/make_unary_operator.hpp>
#include <fcppt/math/detail/sequence.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/optional/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace dim
{

/** \addtogroup fcpptmathdim
*  @{
*/
FCPPT_MATH_DETAIL_MAKE_SYMMETRIC_BINARY_OPERATOR(+)
FCPPT_MATH_DETAIL_MAKE_SYMMETRIC_BINARY_OPERATOR(-)
FCPPT_MATH_DETAIL_MAKE_SYMMETRIC_BINARY_OPERATOR(*)

FCPPT_MATH_DETAIL_MAKE_UNARY_OPERATOR(+)
FCPPT_MATH_DETAIL_MAKE_UNARY_OPERATOR(-)

FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR(+)
FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR(-)
FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR(*)

/** @}*/

/**
\brief Divides a dim by a dim.

\ingroup fcpptmathdim
*/
template<
	typename L,
	typename R,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
inline
fcppt::optional::object<
	fcppt::math::dim::static_<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, /, R),
		N
	>
>
operator /(
	fcppt::math::dim::object<
		L,
		N,
		S1
	> const &_left,
	fcppt::math::dim::object<
		R,
		N,
		S2
	> const &_right
)
{
	// TODO: Simplify this
	return
		fcppt::math::detail::sequence<
			fcppt::math::dim::static_<
				FCPPT_MATH_DETAIL_BINARY_TYPE(L, /, R),
				N
			>
		>(
			fcppt::math::detail::binary_map<
				fcppt::math::dim::static_<
					fcppt::optional::object<
						FCPPT_MATH_DETAIL_BINARY_TYPE(L, /, R)
					>,
					N
				>
			>(
				_left,
				_right,
				[](
					L const &_left_elem,
					R const &_right_elem
				)
				->
				fcppt::optional::object<
					FCPPT_MATH_DETAIL_BINARY_TYPE(L, /, R)
				>
				{
					return
						fcppt::math::div(
							_left_elem,
							_right_elem
						);
				}
			)
		);
}

/**
\brief Divides a dim by a scalar.

\ingroup fcpptmathdim
*/
template<
	typename L,
	typename R,
	fcppt::math::size_type N,
	typename S
>
inline
fcppt::optional::object<
	fcppt::math::dim::static_<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, /, R),
		N
	>
>
operator /(
	fcppt::math::dim::object<
		L,
		N,
		S
	> const &_left,
	R const &_right
)
{
	return
		fcppt::math::detail::sequence<
			fcppt::math::dim::static_<
				FCPPT_MATH_DETAIL_BINARY_TYPE(L, /, R),
				N
			>
		>(
			fcppt::math::detail::map<
				fcppt::math::dim::static_<
					fcppt::optional::object<
						FCPPT_MATH_DETAIL_BINARY_TYPE(L, /, R)
					>,
					N
				>
			>(
				_left,
				[
					&_right
				](
					L const &_left_elem
				)
				{
					return
						fcppt::math::div(
							_left_elem,
							_right
						);
				}
			)
		);
}

}
}
}

#endif
