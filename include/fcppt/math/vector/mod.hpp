//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_MOD_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_MOD_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/mod.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{
template<typename T,typename N,typename S>
vector::basic<T,N,S> const
mod(
	vector::basic<T,N,S> v,
	T const div)
{
	typedef typename
	vector::basic<T,N,S>
	vector;

	typedef typename
	vector::iterator
	vector_iterator;

	for(
		vector_iterator i =
			v.begin();
		i != v.end();
		++i)
		*i =
			fcppt::math::mod(
				*i,
				div);

	return v;
}

template<typename T,typename N,typename S>
vector::basic<T,N,S> const
mod(
	vector::basic<T,N,S> v0,
	vector::basic<T,N,S> const &v1)
{
	typedef typename
	vector::basic<T,N,S>
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
