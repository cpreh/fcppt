//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR_HPP_INCLUDED

#include <fcppt/math/map.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/detail/make_asymmetric_binary_operator_right.hpp>


#define FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR(\
	op\
)\
FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR_RIGHT(\
	op\
)\
\
template<\
	typename L,\
	typename R,\
	fcppt::math::size_type N,\
	typename S\
>\
object<\
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
	N,\
	fcppt::math::static_storage<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
		N\
	>\
> \
operator op(\
	L const &_left,\
	object<R, N, S> const &_right\
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
			_right,\
			[\
				&_left\
			](\
				R const &_right_elem\
			)\
			{\
				return \
					_left \
					op \
					_right_elem; \
			}\
		);\
}

#endif
