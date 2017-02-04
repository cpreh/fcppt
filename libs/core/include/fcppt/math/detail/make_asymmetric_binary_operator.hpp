//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_ASYMMETRIC_BINARY_OPERATOR_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/detail/make_asymmetric_binary_operator_right.hpp>
#include <fcppt/math/detail/map.hpp>


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
inline \
static_<\
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
	N\
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
		fcppt::math::detail::map<\
			static_<\
				result_value_type,\
				N\
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
