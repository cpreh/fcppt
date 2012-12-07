//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_DEFINE_OPERATOR_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_DEFINE_OPERATOR_HPP_INCLUDED

#include <fcppt/preprocessor/detail/enum_params_forward_z.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <fcppt/config/external_end.hpp>


#define FCPPT_SIGNAL_DETAIL_DEFINE_EMPTY_OPERATOR\
	result_type operator()() const\
	{\
	}

#define FCPPT_SIGNAL_DETAIL_DEFINE_OPERATOR(\
	z,\
	n,\
	_\
)\
template<\
	typename T,\
	template<\
		typename\
	> class Base,\
	typename Enable\
>\
template<\
	BOOST_PP_ENUM_PARAMS_Z(\
		z,\
		BOOST_PP_INC(n),\
		typename T\
	)\
>\
typename fcppt::signal::object<\
	T,\
	Base,\
	Enable\
>::result_type \
fcppt::signal::object<\
	T,\
	Base,\
	Enable\
>::operator()(\
	BOOST_PP_ENUM_BINARY_PARAMS_Z(\
		z,\
		BOOST_PP_INC(n),\
		T,\
		&& param\
	)\
) const\
{\
	result_type result(\
		this->initial_result_\
	);\
\
	typename base::connection_list &cur_list(\
		base::connections()\
	);\
\
	for(\
		typename base::connection_list::iterator it(\
			cur_list.begin()\
		); \
		it != cur_list.end();\
		++it\
	) \
		result = \
			this->combiner_(\
				result,\
				it->function()(\
					FCPPT_PP_DETAIL_ENUM_PARAMS_FORWARD_Z(\
						z,\
						BOOST_PP_INC(n),\
						T,\
						param\
					)\
				)\
			);\
	return result;\
}

#endif
