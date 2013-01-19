//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <fcppt/config/external_end.hpp>

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL(\
	z,\
	n,\
	text\
)\
explicit text(\
	BOOST_PP_ENUM_PARAMS(\
		BOOST_PP_INC(n),\
		T const &_param\
	)\
);

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL(\
	max_params,\
	name\
)\
BOOST_PP_REPEAT(\
	max_params,\
	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL,\
	name\
)

#endif
