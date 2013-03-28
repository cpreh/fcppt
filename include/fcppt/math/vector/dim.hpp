//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_DIM_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DIM_HPP_INCLUDED

#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/detail/make_storage_size.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/vector/normal_storage.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

#define FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(\
	op\
)\
template<\
	typename L,\
	typename R,\
	typename N,\
	typename S1,\
	typename S2\
>\
fcppt::math::vector::object<\
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
	N,\
	typename fcppt::math::vector::normal_storage<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
		N\
	>::type\
> const \
operator op(\
	fcppt::math::vector::object<\
		L,\
		N,\
		S1\
	> const  &_left,\
	fcppt::math::dim::object<\
		R,\
		N,\
		S2\
	> const &_right\
)\
{\
	typedef \
	fcppt::math::vector::object<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
		N,\
		typename fcppt::math::vector::normal_storage<\
			FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
			N\
		>::type\
	> result_type;\
\
	result_type result(\
		fcppt::math::detail::make_storage_size(\
			_left.size()\
		)\
	);\
\
	for(\
		typename result_type::size_type index(\
			0u\
		);\
		index < result.size();\
		++index\
	) \
		result[\
			index\
		] = \
			_left[\
				index\
			] \
			op \
			_right[\
				index\
			];\
\
	return \
		result;\
}

FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(+)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(-)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(*)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(/)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(%)

#undef FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION

}
}
}

#endif
