//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_MAKE_PTR_BASE_HPP_INCLUDED
#define FCPPT_DETAIL_MAKE_PTR_BASE_HPP_INCLUDED

#include <fcppt/preprocessor/detail/enum_params_forward_z.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <fcppt/config/external_end.hpp>


#ifndef FCPPT_MAKE_PTR_BASE_MAX_SIZE
#define FCPPT_MAKE_PTR_BASE_MAX_SIZE 20
#endif

#define FCPPT_DETAIL_MAKE_PTR_BASE_FUN(\
	state,\
	count,\
	args\
)\
	template<\
		typename Type,\
		BOOST_PP_ENUM_PARAMS_Z(\
			state,\
			BOOST_PP_INC(\
				count\
			),\
			typename T\
		)\
	>\
	BOOST_PP_TUPLE_ELEM(3, 1, args) <\
		Type\
	> \
	BOOST_PP_CAT(make_, BOOST_PP_TUPLE_ELEM(3, 0, args)) (\
		BOOST_PP_ENUM_BINARY_PARAMS_Z(\
			state,\
			BOOST_PP_INC(\
				count\
			),\
			T,\
			param\
		)\
	)\
	{\
		return \
			BOOST_PP_TUPLE_ELEM(3, 1, args)<\
				Type\
			>(\
				BOOST_PP_TUPLE_ELEM(3, 2, args) (\
					FCPPT_PP_DETAIL_ENUM_PARAMS_FORWARD_Z(\
						state,\
						BOOST_PP_INC(\
							count\
						),\
						T,\
						param\
					)\
				)\
			);\
	}

#define FCPPT_DETAIL_MAKE_PTR_BASE(\
	name,\
	ptr_type,\
	new_expr\
)\
BOOST_PP_REPEAT(\
	FCPPT_MAKE_PTR_BASE_MAX_SIZE,\
	FCPPT_DETAIL_MAKE_PTR_BASE_FUN,\
	(name, ptr_type, new_expr)\
)\
template<\
	typename Type\
>\
ptr_type<\
	Type\
> \
make_##name()\
{\
	return \
		ptr_type<\
			Type\
		>(\
			new_expr()\
		);\
}

#endif
