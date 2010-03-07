//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_VECTOR_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T,
	typename N,
	typename M,
	typename S1,
	typename S2
>
fcppt::math::vector::basic<T, M, S2>
operator *(
	basic<T, N, M, S1> const &m,
	vector::basic<T, N, S2> const &v
)
{
	typedef vector::basic<T, M, S2> result_type;

	result_type ret(
		result_type::null()
	);

	for(
		typename result_type::size_type i = 0;
		i < v.size();
		++i
	)
		for(
			typename basic<T, N, M, S2>::size_type j = 0;
			j < N::value;
			++j
		)
			ret[i] += v[j] * m[j][i];
	return ret;
}

}
}
}

#endif
