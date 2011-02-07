#ifndef FCPPT_MATH_GENERATE_BINARY_VECTORS_HPP_INCLUDED
#define FCPPT_MATH_GENERATE_BINARY_VECTORS_HPP_INCLUDED

#include <fcppt/math/detail/generate_binary_vectors.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <vector>

namespace fcppt
{
namespace math
{
/**
	Generates the binary vectors of type T in dimension N. Examples:
	T = int,
	N = 2:

	(0,0)
	(1,0)
	(0,1)
	(1,1)

	T = int,
	N = 3:
	(0,0,0)
	(1,0,0)
	(0,1,0)
	(1,1,0)
	(0,0,1)
	(1,0,1)
	(0,1,1)
	(1,1,1)

	This is used in box::corner_points.
 */
template<typename T,fcppt::math::size_type N>
std::vector
<
	typename
	fcppt::math::vector::static_<T,N>::type
> const
generate_binary_vectors()
{
	typedef
	std::vector
	<
		typename
		fcppt::math::vector::static_<T,N>::type
	>
	result_type;

	result_type result;

	fcppt::math::detail::generate_binary_vectors<static_cast<fcppt::math::size_type>(N-1) >(
		result,
		result_type::value_type::null());

	return result;
}
}
}

#endif
