//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DETAIL_ENUM_PARAMS_FORWARD_M_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_DETAIL_ENUM_PARAMS_FORWARD_M_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


#define FCPPT_PP_DETAIL_ENUM_PARAMS_FORWARD_M_II(\
	z,\
	n,\
	param1,\
	param2\
)\
	BOOST_PP_COMMA_IF(n) \
	std::forward<\
		BOOST_PP_CAT(param1, n)\
	>(\
		BOOST_PP_CAT(param2, n)\
	)

#define FCPPT_PP_DETAIL_ENUM_PARAMS_FORWARD_M(\
	z,\
	n,\
	params\
)\
	FCPPT_PP_DETAIL_ENUM_PARAMS_FORWARD_M_II(\
		z,\
		n,\
		BOOST_PP_TUPLE_ELEM(2, 0, params),\
		BOOST_PP_TUPLE_ELEM(2, 1, params)\
	)

#endif
