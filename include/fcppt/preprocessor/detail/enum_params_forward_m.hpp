//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DETAIL_ENUM_PARAMS_FORWARD_M_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_ENUM_PARAMS_FORWARD_M_HPP_INCLUDED

#include <boost/preprocessor/punctuation/comma_if.hpp>

#define FCPPT_PP_DETAIL_ENUM_PARAMS_FORWARD_M(\
	z,\
	n,\
	param\
)\
	BOOST_PP_COMMA_IF(n) forward(param ## n)

#endif
