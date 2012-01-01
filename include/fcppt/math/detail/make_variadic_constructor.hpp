//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_HPP_INCLUDED

#include <fcppt/math/detail/dim_matches.hpp>
#include <fcppt/math/detail/initial_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <fcppt/config/external_end.hpp>


#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_ASSIGN(z, n, text)\
*(data() + n) = text##n;

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_IMPL(\
	z,\
	n,\
	text\
)\
BOOST_PP_TUPLE_REM_CTOR(BOOST_PP_TUPLE_ELEM(2, 0, text),BOOST_PP_TUPLE_ELEM(2, 1, text)) (\
	BOOST_PP_ENUM_PARAMS(\
		BOOST_PP_INC(n),\
		T const &_param\
	)\
)\
{\
	BOOST_STATIC_ASSERT((\
		math::detail::dim_matches<\
			BOOST_PP_INC(n),\
			dim_wrapper::value\
		>::value\
	));\
	\
	::fcppt::math::detail::initial_size(\
		storage_,\
		static_cast<\
			size_type\
		>(\
			BOOST_PP_INC(n)\
		)\
	); \
	\
	BOOST_PP_REPEAT(\
		BOOST_PP_INC(n),\
		FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_ASSIGN,\
		_param\
	)\
}

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR(\
	max_params,\
	template_pre\
)\
BOOST_PP_REPEAT(\
	max_params,\
	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_IMPL,\
	template_pre\
)

#endif
