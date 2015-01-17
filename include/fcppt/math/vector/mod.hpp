//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_MOD_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_MOD_HPP_INCLUDED

#include <fcppt/math/mod.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{
/**
\brief Calculate vector modulo a scalar
*/
template<typename T,typename N,typename S>
fcppt::math::vector::object<T,N,S> const
mod(
	fcppt::math::vector::object<T,N,S> v,
	T const div)
{
	for(
		auto &item : v)
		item =
			fcppt::math::mod(
				item,
				div);

	return v;
}

template<typename T,typename N,typename S>
fcppt::math::vector::object<T,N,S> const
mod(
	fcppt::math::vector::object<T,N,S> v0,
	fcppt::math::vector::object<T,N,S> const &v1)
{
	typedef typename
	fcppt::math::vector::object<T,N,S>
	vector;

	typedef typename
	vector::size_type
	vector_size_type;

	for(
		vector_size_type i =
			0;
		i < v0.size();
		++i)
		v0[i] =
			fcppt::math::mod(
				v0[i],
				v1[i]);

	return v0;
}
}
}
}

#endif
