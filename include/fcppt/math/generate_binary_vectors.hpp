#ifndef FCPPT_MATH_GENERATE_BINARY_VECTORS_HPP_INCLUDED
#define FCPPT_MATH_GENERATE_BINARY_VECTORS_HPP_INCLUDED

#include <fcppt/math/detail/generate_binary_vectors.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/container/array.hpp>
#include <cstddef>

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
fcppt::container::array
<
	typename fcppt::math::vector::static_<T,N>::type,
	static_cast<std::size_t>(1u << N)
> const
generate_binary_vectors()
{
	typedef typename 
	fcppt::math::vector::static_<T,N>::type
	vector_type;
	
	typedef
	fcppt::container::array
	<
		vector_type,
		static_cast<std::size_t>(1u << N)
	>
	result_type;

	result_type result;
	typename result_type::iterator it = result.begin();

	fcppt::math::detail::generate_binary_vectors
	<
		static_cast<fcppt::math::size_type>(N-1),
		typename result_type::iterator,
		vector_type
	>(
		it,
		vector_type::null());

	return result;
}
}
}

#endif
