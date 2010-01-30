//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL_HPP_INCLUDED

#include <fcppt/config.h>
#ifndef FCPPT_HAVE_VARIADIC_TEMPLATES
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#endif

#ifdef FCPPT_HAVE_VARIADIC_TEMPLATES
#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL(name) \
	template<\
		typename... Args\
	> \
	explicit name(Args... args); \
private: \
	template<\
		typename... Args,\
		typename Arg\
	> \
	void set_impl( \
		size_type i, \
		Arg const &arg, \
		Args... args); \
\
	template<\
		typename Arg\
	>\
	void set_impl( \
		size_type i, \
		Arg const &arg);
#else

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL(\
	z,\
	n,\
	text\
)\
explicit text(\
	BOOST_PP_ENUM_PARAMS(\
		BOOST_PP_INC(n),\
		T const& param\
	)\
);

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL(\
	name\
)\
BOOST_PP_REPEAT(\
	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_MAX_SIZE,\
	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL,\
	name\
)

#endif


#endif
