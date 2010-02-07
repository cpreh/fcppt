//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_TRANSPOSE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_TRANSPOSE_HPP_INCLUDED

#include <fcppt/math/matrix/basic_fwd.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>

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
	typename S
>
basic<T, M, N, S> const
transpose(
	basic<T, N, M, S> const &t
)
{
	typedef basic<T, M, N, S> ret_type;

	ret_type ret(
		typename ret_type::dim(
			t.rows(),
			t.columns()
		)
	);

	typedef typename ret_type::size_type size_type;
	for(size_type i = 0; i < t.rows(); ++i)
		for(size_type j = 0; j < t.columns(); ++j)
			if(j < t.rows() && i < t.columns())
				ret[j][i] = t[i][j];
	return ret;

}

}
}
}

#endif
