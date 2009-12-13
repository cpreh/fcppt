/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_SIGNAL_DETAIL_DEFINE_OPERATOR_HPP_INCLUDED
#define SGE_SIGNAL_DETAIL_DEFINE_OPERATOR_HPP_INCLUDED

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/next_prior.hpp>

#define SGE_SIGNAL_DETAIL_DEFINE_EMPTY_OPERATOR\
	result_type operator()()\
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

#define SGE_SIGNAL_DETAIL_DEFINE_OPERATOR(z,n,_)\
	template<\
	BOOST_PP_ENUM_PARAMS_Z(z,BOOST_PP_INC(n),typename T)\
	>\
	result_type operator()(\
		BOOST_PP_ENUM_BINARY_PARAMS(BOOST_PP_INC(n),T, const &param))\
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
