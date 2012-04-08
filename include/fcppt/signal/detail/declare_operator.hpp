//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_DECLARE_OPERATOR_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_DECLARE_OPERATOR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <fcppt/config/external_end.hpp>


#define FCPPT_SIGNAL_DETAIL_DECLARE_OPERATOR(\
	z,\
	n,\
	_\
)\
template<\
	BOOST_PP_ENUM_PARAMS_Z(\
		z,\
		BOOST_PP_INC(n),\
		typename T\
	)\
>\
result_type \
operator()(\
	BOOST_PP_ENUM_BINARY_PARAMS_Z(\
		z,\
		BOOST_PP_INC(n),\
		T,\
		const &param\
	)\
) const;\

#endif
