//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_ARITHMETIC_HPP_INCLUDED

#include <fcppt/math/matrix/normal_storage.hpp>
#include <fcppt/math/matrix/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

#define FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION(op)\
template<\
	typename T,\
	typename N,\
	typename M,\
	typename S1,\
	typename S2\
>\
object<\
	T,\
	N,\
	M,\
	typename normal_storage<\
		T,\
		N,\
		M\
	>::type\
> const \
operator op(\
	object<T, N, M, S1> const &a,\
	object<T, N, M, S2> const &b\
)\
{\
	return \
		object<\
			T,\
			N,\
			M,\
			typename normal_storage<\
				T,\
				N,\
				M\
			>::type\
		>(\
			a\
		)\
		op##= b;\
}

FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION(+)
FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION(-)

#undef FCPPT_MATH_MAKE_FREE_MATRIX_FUNCTION

template<
	typename T,
	typename N,
	typename M1,
	typename M2,
	typename S1,
	typename S2
>
object<
	T,
	M1,
	M2,
	typename normal_storage<
		T,
		M1,
		M2
	>::type
> const
operator *(
	object<T, M1, N, S1> const &a,
	object<T, N, M2, S2> const &b
)
{
	typedef object<
		T,
		M1,
		M2,
		typename normal_storage<
			T,
			M1,
			M2
		>::type
	> result_type;

	result_type ret(
		typename result_type::dim(
			a.rows(),
			b.columns()
		)
	);

	for(
		typename object<T, M1, N, S1>::size_type i = 0;
		i < M1::value;
		++i
	)
		for(
			typename object<T, N, M2, S2>::size_type j = 0;
			j < M2::value;
			++j
		)
		{
			typename result_type::value_type v(0);

			for(
				typename result_type::size_type r = 0;
				r < N::value;
				++r
			)
				v += a[i][r] * b[r][j];
			ret[i][j] = v;
		}

	return ret;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
object<
	T,
	N,
	M,
	typename normal_storage<
		T,
		N,
		M
	>::type
> const
operator *(
	object<T, N, M, S> const &a,
	T const &s
)
{
	return
		object<
			T,
			N,
			M,
			typename normal_storage<
				T,
				N,
				M
			>::type
		>(
			a
		)
		*= s;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
object<
	T,
	N,
	M,
	typename normal_storage<
		T,
		N,
		M
	>::type
> const
operator *(
	T const &s,
	object<T, N, M, S> const &a
)
{
	return a * s;
}

template<
	typename T,
	typename N,
	typename M,
	typename S
>
object<
	T,
	N,
	M,
	typename normal_storage<
		T,
		N,
		M
	>::type
> const
operator /(
	object<T, N, M, S> a,
	T const &s
)
{
	return
		object<
			T,
			N,
			M,
			typename normal_storage<
				T,
				N,
				M
			>::type
		>(
			a
		)
		/= s;
}

}
}
}

#endif
