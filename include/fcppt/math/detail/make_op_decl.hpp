//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MAKE_OP_DECL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_OP_DECL_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/tuple/rem.hpp>
#include <fcppt/config/external_end.hpp>


#define FCPPT_MATH_DETAIL_MAKE_OP_DECL(\
	decl,\
	param,\
	arity,\
	op\
)\
decl \
object & \
operator op ( \
	BOOST_PP_TUPLE_REM(arity)param const &\
);

#endif
