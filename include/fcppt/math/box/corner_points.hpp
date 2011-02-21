//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_CORNER_POINTS_HPP_INCLUDED
#define FCPPT_MATH_BOX_CORNER_POINTS_HPP_INCLUDED

#include <fcppt/container/array.hpp>
#include <fcppt/math/generate_binary_vectors.hpp>
#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <boost/foreach.hpp>
#include <cstddef>

namespace fcppt
{
namespace math
{
namespace box
{
// Returns the 2^N corner points of the given box.
template<typename T,size_type N>
fcppt::container::array
<
	typename fcppt::math::vector::static_<T,N>::type,
	static_cast<std::size_t>(1u << N)
> const
corner_points(
	basic<T,N> const &p)
{
	typedef typename
	fcppt::math::vector::static_<T,N>::type
	vector_type;

	typedef
	fcppt::container::array
	<
		typename fcppt::math::vector::static_<T,N>::type,
		static_cast<std::size_t>(1u << N)
	>
	result_type;

	result_type result = 
		fcppt::math::generate_binary_vectors<T,N>();

	BOOST_FOREACH(
		vector_type &v,
		result)
		v = 
			p.pos() + v * fcppt::math::dim::structure_cast<vector_type>(p.dimension());
		
	return result;
}
}
}
}

#endif
