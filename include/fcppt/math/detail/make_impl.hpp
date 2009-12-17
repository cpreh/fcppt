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


#ifndef FCPPT_MATH_DETAIL_MAKE_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_IMPL_HPP_INCLUDED

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>

#define FCPPT_MATH_DETAIL_MAKE_IMPL_COUNT(\
	z,\
	count,\
	text\
)\
template<\
	typename T\
>\
typename static_<\
	T,\
	BOOST_PP_INC(count)\
>::type \
make(\
	BOOST_PP_ENUM_PARAMS_Z(\
		z,\
		BOOST_PP_INC(count),\
		T const &param\
	)\
)\
{\
	return\
		typename static_<\
			T,\
			BOOST_PP_INC(count)\
		>::type(\
			BOOST_PP_ENUM_PARAMS_Z(\
				z,\
				BOOST_PP_INC(count),\
				param\
			)\
		);\
}

#define FCPPT_MATH_DETAIL_MAKE_IMPL(\
	count\
)\
BOOST_PP_REPEAT(\
	count,\
	FCPPT_MATH_DETAIL_MAKE_IMPL_COUNT,\
	void\
)

#endif
