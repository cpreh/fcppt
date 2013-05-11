//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_SIMPLE_FREE_FUNCTION_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_SIMPLE_FREE_FUNCTION_HPP_INCLUDED

#include <fcppt/math/binary_map.hpp>
#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/detail/binary_type.hpp>


#define FCPPT_MATH_DETAIL_MAKE_SIMPLE_FREE_FUNCTION(\
	op\
)\
template<\
	typename L,\
	typename R,\
	typename N,\
	typename S1,\
	typename S2\
>\
object<\
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
	N,\
	typename fcppt::math::static_storage<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
		N\
	>::type\
> const \
operator op(\
	object<L, N, S1> const &_left,\
	object<R, N, S2> const &_right\
)\
{\
	typedef \
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R)\
	result_value_type; \
\
	return \
		fcppt::math::binary_map<\
			object<\
				result_value_type,\
				N,\
				typename \
				fcppt::math::static_storage<\
					result_value_type,\
					N\
				>::type \
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
					_right_elem; \
			}\
		);\
}

#endif
