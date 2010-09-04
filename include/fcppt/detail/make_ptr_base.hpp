//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_MAKE_PTR_BASE_HPP_INCLUDED
#define FCPPT_DETAIL_MAKE_PTR_BASE_HPP_INCLUDED

#include <fcppt/preprocessor/enum_params_forward_z.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>

#ifndef FCPPT_MAKE_PTR_BASE_MAX_SIZE
#define FCPPT_MAKE_PTR_BASE_MAX_SIZE 20
#endif

#define FCPPT_DETAIL_MAKE_PTR_BASE_FUN(\
	z,\
	n,\
	ptr_type\
)\
	template<\
		typename Type,\
		BOOST_PP_ENUM_PARAMS_Z(\
			z,\
			BOOST_PP_INC(n),\
			typename T\
		)\
	>\
	ptr_type<\
		Type\
	> \
	make_##ptr_type (\
		BOOST_PP_ENUM_BINARY_PARAMS(\
			BOOST_PP_INC(n),\
			T,\
			const &param\
		)\
	)\
	{\
		return \
			ptr_type<\
				Type\
			>(\
				new Type(\
					FCPPT_PP_ENUM_PARAMS_FORWARD_Z(\
						z,\
						BOOST_PP_INC(n),\
						T,\
						param\
					)\
				)\
			);\
	}

#define FCPPT_DETAIL_MAKE_PTR_BASE(\
	ptr_type\
)\
BOOST_PP_REPEAT(\
	FCPPT_MAKE_PTR_BASE_MAX_SIZE,\
	FCPPT_DETAIL_MAKE_PTR_BASE_FUN,\
	ptr_type\
)\
template<\
	typename Type\
>\
ptr_type<\
	Type\
> \
make_##ptr_type()\
{\
	return \
		ptr_type<\
			Type\
		>(\
			new Type()\
		);\
}

#endif
