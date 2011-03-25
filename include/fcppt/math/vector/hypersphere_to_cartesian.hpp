//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_HYPERSPHERE_TO_CARTESIAN_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_HYPERSPHERE_TO_CARTESIAN_HPP_INCLUDED

#include <fcppt/math/vector/basic.hpp>
#include <fcppt/math/vector/static.hpp>
#include <cmath>

namespace fcppt
{
namespace math
{
namespace vector
{
/// Calculate the n dimensional polar coordinates, also called "hyperspherical coordinates"
/**
	Formula taken from: 
	http://en.wikipedia.org/wiki/Hypersphere#Hyperspherical_coordinates

	Given an (n-1)-dimensional angle vector this returns an
	n-dimensional unit vector in n-dimensional cartesian coordinates. If
	you want a scaled version of the result, do it yourself using
	operator*(T,vector).

	@param angles The n-1 dimensional angle vector
 */
template<typename T,typename N,typename S>
typename
static_<T,N::value+1>::type const
hypersphere_to_cartesian(
	basic<T,N,S> const &angles)
{
	typedef typename
	static_<T,N::value+1>::type 
	result_type;

	typedef typename
	result_type::size_type
	size_type;

	typedef typename
	result_type::value_type
	value_type;

	result_type result;
	for(size_type i = 0; i < result.size(); ++i)
	{
		// Hehe..."sins"
		value_type sins = 
			static_cast<value_type>(
				1);
		for(size_type j = 0; j < i; ++j)
			sins *= 
				std::sin(
					angles[j]);
		result[i] = 
			sins * 
			(
			i >= angles.size()
			?
				static_cast<value_type>(1)
			:
				std::cos(
					angles[i]));
	}
	return result;
}
}
}
}

#endif
