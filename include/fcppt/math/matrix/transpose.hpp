//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_TRANSPOSE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_TRANSPOSE_HPP_INCLUDED

#include <fcppt/no_init.hpp>
#include <fcppt/math/matrix/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Calculates a transposed matrix
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\tparam M The matrix's row dimension type
\tparam N The matrix's column dimension type
\tparam S The matrix's storage type
\param t The matrix
*/
template<
	typename T,
	typename N,
	typename M,
	typename S
>
fcppt::math::matrix::object<
	T,
	M,
	N,
	S
> const
transpose(
	fcppt::math::matrix::object<
		T,
		N,
		M,
		S
	> const &t
)
{
	typedef object<T, M, N, S> ret_type;

	ret_type ret{
		fcppt::no_init()
	};

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
