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


#ifndef FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL_HPP_INCLUDED

#include <fcppt/config.h>
#ifndef FCPPT_HAVE_VARIADIC_TEMPLATES
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#endif

#ifdef FCPPT_HAVE_VARIADIC_TEMPLATES
#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL(name) \
	template<\
		typename... Args\
	> \
	explicit name(Args... args); \
private: \
	template<\
		typename... Args,\
		typename Arg\
	> \
	void set_impl( \
		size_type i, \
		Arg const &arg, \
		Args... args); \
\
	template<\
		typename Arg\
	>\
	void set_impl( \
		size_type i, \
		Arg const &arg);
#else

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL(\
	z,\
	n,\
	text\
)\
explicit text(\
	BOOST_PP_ENUM_PARAMS(\
		BOOST_PP_INC(n),\
		T const& param\
	)\
);

#define FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL(\
	name\
)\
BOOST_PP_REPEAT(\
	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_MAX_SIZE,\
	FCPPT_MATH_DETAIL_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL,\
	name\
)

#endif


#endif
