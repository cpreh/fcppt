//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_SYMMETRIC_BINARY_OPERATOR_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_SYMMETRIC_BINARY_OPERATOR_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_map.hpp>
#include <fcppt/math/detail/binary_type.hpp>


#define FCPPT_MATH_DETAIL_MAKE_SYMMETRIC_BINARY_OPERATOR(\
	op\
)\
template<\
	typename L,\
	typename R,\
	fcppt::math::size_type N,\
	typename S1,\
	typename S2\
>\
inline \
static_<\
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
	N\
> \
operator op(\
	object<L, N, S1> const &_left,\
	object<R, N, S2> const &_right\
)\
{\
	return \
		fcppt::math::detail::binary_map<\
			static_<\
				FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
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
					_right_elem; \
			}\
		);\
}

#endif
