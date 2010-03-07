//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_HPP_INCLUDED

#include <fcppt/math/detail/initial_size.hpp>
#include <fcppt/math/detail/dim_matches.hpp>
#include <boost/static_assert.hpp>
#include <fcppt/config.hpp>
#ifndef FCPPT_HAVE_VARIADIC_TEMPLATES
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#endif

#ifdef FCPPT_HAVE_VARIADIC_TEMPLATES
#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR(name) \
	FCPPT_MATH_DETAIL_TEMPLATE_PRE \
	template<\
		typename... Args\
	> \
	FCPPT_MATH_DETAIL_DEF_PRE::name(\
		Args... args\
	) \
	{ \
		::fcppt::math::detail::initial_size(\
			storage,\
			sizeof...(args)); \
		set_impl(0, args...); \
	} \
\
	FCPPT_MATH_DETAIL_TEMPLATE_PRE \
	template<\
		typename... Args,\
		typename Arg\
	> \
	void \
	FCPPT_MATH_DETAIL_DEF_PRE::set_impl( \
		size_type const i, \
		Arg const &arg, \
		Args... args\
	) \
	{ \
		*(data() + i) = arg; \
		set_impl(i + 1, args...); \
	} \
\
	FCPPT_MATH_DETAIL_TEMPLATE_PRE \
	template<\
		typename Arg\
	>\
	void \
	FCPPT_MATH_DETAIL_DEF_PRE::set_impl( \
		size_type const i, \
		Arg const &arg\
	) \
	{ \
		*(data() + i) = arg; \
	}
#else
#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_ASSIGN(z, n, text)\
*(data() + n) = text##n;

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_IMPL(z, n, text)\
FCPPT_MATH_DETAIL_TEMPLATE_PRE \
FCPPT_MATH_DETAIL_DEF_PRE :: text(\
	BOOST_PP_ENUM_PARAMS(\
		BOOST_PP_INC(n),\
		T const& param\
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
		storage,\
		BOOST_PP_INC(n)\
	); \
	\
	BOOST_PP_REPEAT(\
		BOOST_PP_INC(n),\
		FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_ASSIGN,\
		param\
	)\
}

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR(\
	name\
)\
BOOST_PP_REPEAT(\
	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_MAX_SIZE,\
	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_IMPL,\
	name\
)

#endif

#endif
