//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_UNARY_OPERATOR_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_UNARY_OPERATOR_HPP_INCLUDED

#include <fcppt/math/map.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/unary_type.hpp>


#define FCPPT_MATH_DETAIL_MAKE_UNARY_OPERATOR(\
	op\
)\
template<\
	typename T,\
	fcppt::math::size_type N,\
	typename S\
>\
static_<\
	FCPPT_MATH_DETAIL_UNARY_TYPE(T, op),\
	N\
> \
operator op(\
	object<\
		T,\
		N,\
		S\
	> const &_arg\
)\
{\
	return \
		fcppt::math::map<\
			static_<\
				FCPPT_MATH_DETAIL_UNARY_TYPE(T, op), \
				N\
			>\
		>(\
			_arg,\
			[](\
				T const &_value\
			)\
			{\
				return \
					op \
					_value;\
			}\
		);\
}

#endif
