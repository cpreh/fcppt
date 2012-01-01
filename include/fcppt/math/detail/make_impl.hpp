//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_IMPL_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <fcppt/config/external_end.hpp>


#define FCPPT_MATH_DETAIL_MAKE_IMPL_COUNT(\
	z,\
	count,\
	text\
)\
template<\
	typename T\
>\
typename static_<\
	T,\
	BOOST_PP_INC(count)\
>::type \
make(\
	BOOST_PP_ENUM_PARAMS_Z(\
		z,\
		BOOST_PP_INC(count),\
		T const &param\
	)\
)\
{\
	return\
		typename static_<\
			T,\
			BOOST_PP_INC(count)\
		>::type(\
			BOOST_PP_ENUM_PARAMS_Z(\
				z,\
				BOOST_PP_INC(count),\
				param\
			)\
		);\
}

#define FCPPT_MATH_DETAIL_MAKE_IMPL(\
	count\
)\
BOOST_PP_REPEAT(\
	count,\
	FCPPT_MATH_DETAIL_MAKE_IMPL_COUNT,\
	void\
)

#endif
