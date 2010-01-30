//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_DEFINE_OPERATOR_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_DEFINE_OPERATOR_HPP_INCLUDED

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/next_prior.hpp>

#define FCPPT_SIGNAL_DETAIL_DEFINE_EMPTY_OPERATOR\
	result_type operator()() const\
	{\
		if (base::connections().empty()) \
			return result_type(); \
		result_type t = base::connections().begin()->function()();\
		for (typename connection_list::iterator i = boost::next(base::connections().begin());\
		     i != base::connections().end();\
				 ++i)\
			t = combiner_(i->function()(),t);\
		return t;\
	}

#define FCPPT_SIGNAL_DETAIL_DEFINE_OPERATOR(z,n,_)\
	template<\
	BOOST_PP_ENUM_PARAMS_Z(z,BOOST_PP_INC(n),typename T)\
	>\
	result_type operator()(\
		BOOST_PP_ENUM_BINARY_PARAMS(BOOST_PP_INC(n),T, const &param)) const\
	{\
		if (base::connections().empty()) \
			return result_type(); \
		result_type t = base::connections().begin()->function()(\
			BOOST_PP_ENUM_PARAMS_Z(z,BOOST_PP_INC(n),param));\
		for (typename connection_list::iterator i = base::connections().begin();\
		     i != base::connections().end();\
				 ++i)\
			t = combiner_(\
				t,\
				i->function()(\
					BOOST_PP_ENUM_PARAMS_Z(z,BOOST_PP_INC(n),param)));\
		return t;\
	}

#endif
