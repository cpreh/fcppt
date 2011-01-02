//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_ENUM_PARAMS_FORWARD_Z_HPP_INCLUDED
#define FCPPT_PREPROCESSOR_ENUM_PARAMS_FORWARD_Z_HPP_INCLUDED

#include <fcppt/preprocessor/detail/enum_params_forward_m.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

#define FCPPT_PP_ENUM_PARAMS_FORWARD_Z(\
	z,\
	count,\
	param1,\
	param2\
)\
	BOOST_PP_REPEAT_ ## z(count, FCPPT_PP_DETAIL_ENUM_PARAMS_FORWARD_M, (param1, param2))

#endif
