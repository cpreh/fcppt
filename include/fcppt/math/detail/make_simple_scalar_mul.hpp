//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_MUL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_MUL_HPP_INCLUDED

#include <fcppt/math/map.hpp>
#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/detail/make_simple_scalar_left.hpp>


#define FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_MUL \
FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_LEFT(\
	*\
)\
\
template<\
	typename L,\
	typename R,\
	typename N,\
	typename S\
>\
object<\
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),\
	N,\
	typename fcppt::math::static_storage<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),\
		N\
	>::type\
> const \
operator *(\
	L const &_left,\
	object<R, N, S> const &_right\
)\
{\
	typedef \
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R)\
	result_value_type; \
\
	return \
		fcppt::math::map<\
			object<\
				result_value_type,\
				N,\
				typename fcppt::math::static_storage<\
					result_value_type,\
					N\
				>::type\
			>\
		>(\
			_right,\
			[\
				&_left\
			](\
				R const &_right_elem\
			)\
			{\
				return \
					_left \
					* \
					_right_elem; \
			}\
		);\
}

#endif
