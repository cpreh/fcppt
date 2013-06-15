//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_LEFT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_LEFT_HPP_INCLUDED

#include <fcppt/math/map.hpp>
#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/detail/binary_type.hpp>


#define FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_LEFT(\
	op\
)\
template<\
	typename L,\
	typename R,\
	typename N,\
	typename S\
>\
object<\
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
	N,\
	fcppt::math::static_storage<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
		N\
	>\
> const \
operator op(\
	object<L, N, S> const &_left,\
	R const &_right\
)\
{\
	typedef \
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R)\
	result_value_type; \
\
	return \
		fcppt::math::map<\
			object<\
				result_value_type,\
				N,\
				fcppt::math::static_storage<\
					result_value_type,\
					N\
				>\
			>\
		>(\
			_left,\
			[\
				&_right\
			](\
				L const &_left_elem\
			)\
			{\
				return \
					_left_elem \
					op \
					_right;\
			}\
		);\
}

#endif
