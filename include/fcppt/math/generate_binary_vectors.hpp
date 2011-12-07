//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_GENERATE_BINARY_VECTORS_HPP_INCLUDED
#define FCPPT_MATH_GENERATE_BINARY_VECTORS_HPP_INCLUDED

#include <fcppt/container/array.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/generate_binary_vectors.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
/**
\brief Generates vectors consisting of zeros and ones
\ingroup fcpptmath
\tparam Any type that you can <code>static_cast</code> 0 and 1 to

Generates the binary vectors of type <code>T</code> in dimension
<code>N</code>. Examples:

<pre>
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
</pre>

This is used, for example, in fcppt::math::box::corner_points.

Example:

\code
typedef
fcppt::math::vector::static_<int,3>::type
vector3;

// In dimension 3, we have 2^3=8 vectors, so typedef an array of this size
// here:

typedef
fcppt::container::array<vector3,8>
binary_vectors;

binary_vectors vs(
	fcppt::math::generate_binary_vectors<int,3>());

// Outputs 0,0,0
std::cout << vs[0];

// Outputs 0,0,1
std::cout << vs[1];

// ...
\endcode
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
