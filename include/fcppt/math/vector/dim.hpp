//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_DIM_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DIM_HPP_INCLUDED

#include <fcppt/math/binary_map.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>


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
	fcppt::math::size_type N,\
	typename S1,\
	typename S2\
>\
fcppt::math::vector::static_<\
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
	N \
> \
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
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R)\
	result_value_type; \
\
	return \
		fcppt::math::binary_map<\
			fcppt::math::vector::static_<\
				result_value_type,\
				N\
			>\
		>(\
			_left,\
			_right,\
			[](\
				L const &_left_elem,\
				R const &_right_elem\
			)\
			{\
				return \
					_left_elem \
					op \
					_right_elem;\
			}\
		);\
}

/** \addtogroup fcpptmathvector
*  @{
*/
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(+)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(-)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(*)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(/)
FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION(%)
/** @}*/

#undef FCPPT_MATH_MAKE_FREE_VECTOR_DIM_FUNCTION

}
}
}

#endif
