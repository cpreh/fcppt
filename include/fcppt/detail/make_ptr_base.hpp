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


#ifndef FCPPT_DETAIL_MAKE_PTR_BASE_HPP_INCLUDED
#define FCPPT_DETAIL_MAKE_PTR_BASE_HPP_INCLUDED

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>

#ifndef FCPPT_MAKE_PTR_BASE_MAX_SIZE
#define FCPPT_MAKE_PTR_BASE_MAX_SIZE 20
#endif

#define FCPPT_DETAIL_MAKE_PTR_BASE_FUN(z, n, ptr_type)\
	template<\
		typename Type,\
		BOOST_PP_ENUM_PARAMS_Z(\
			z,\
			BOOST_PP_INC(n),\
			typename T)\
	>\
	ptr_type<\
		Type\
	> \
	make_##ptr_type (\
		BOOST_PP_ENUM_BINARY_PARAMS(\
			BOOST_PP_INC(n),\
			T,\
			const &param)\
		)\
	{\
		return ptr_type<\
			Type\
		>(\
			new Type(\
				BOOST_PP_ENUM_PARAMS_Z(\
					z,\
					BOOST_PP_INC(n),\
					param)\
				)\
			);\
	}

#define FCPPT_DETAIL_MAKE_PTR_BASE(ptr_type)\
BOOST_PP_REPEAT(\
	FCPPT_MAKE_PTR_BASE_MAX_SIZE,\
	FCPPT_DETAIL_MAKE_PTR_BASE_FUN,\
	ptr_type)\
template<\
	typename Type\
>\
ptr_type<\
	Type\
> \
make_##ptr_type()\
{\
	return ptr_type<Type>(\
		new Type()\
	);\
}
// TODO: can't the macro generate this, too?
// TODO: make the return value const for shared_ptrs

#endif
