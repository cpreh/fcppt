//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_MUL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_SIMPLE_SCALAR_MUL_HPP_INCLUDED

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
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
	N,\
	typename normal_storage<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
		N\
	>::type\
> const \
operator*(\
	L const &_left,\
	object<R, N, S> const &_right\
)\
{\
	typedef \
	object<\
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
		N,\
		typename normal_storage<\
			FCPPT_MATH_DETAIL_BINARY_TYPE(L, op, R),\
			N\
		>::type\
	> result_type; \
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
	)\
		result[\
			index\
		] = \
			_left \
			op \
			_right[\
				index\
			];\
\
	return \
		result;\
}

#endif
