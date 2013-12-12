//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_UNARY_OPERATOR_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_UNARY_OPERATOR_HPP_INCLUDED

#include <fcppt/math/map.hpp>
#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/detail/unary_type.hpp>


#define FCPPT_MATH_DETAIL_MAKE_UNARY_OPERATOR(\
	op\
)\
template<\
	typename T,\
	typename N,\
	typename S\
>\
object<\
	FCPPT_MATH_DETAIL_UNARY_TYPE(T, op),\
	N,\
	fcppt::math::static_storage<\
		FCPPT_MATH_DETAIL_UNARY_TYPE(T, op),\
		N\
	>\
> const \
operator op(\
	object<\
		T,\
		N,\
		S\
	> const &_arg\
)\
{\
	typedef \
	FCPPT_MATH_DETAIL_UNARY_TYPE(T, op) \
	result_value_type;\
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
