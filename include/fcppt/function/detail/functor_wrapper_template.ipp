/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2009 Thomas Heller (thom.heller@gmail.com)

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


#ifndef SGE_FUNCTION_DETAIL_FUNCTOR_WRAPPER_HPP_INCLUDED
#error "This file is not a standalone header. #include <sge/function/detail/functor_wrapper.hpp> instead."
#endif

#ifndef SGE_FUNCTION_DETAIL_FUNCTOR_WRAPPER_TEMPLATE_HPP_INCLUDED
#define SGE_FUNCTION_DETAIL_FUNCTOR_WRAPPER_TEMPLATE_HPP_INCLUDED

#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>

#endif

#define SGE_FUNCTION_OBJECT_PP_TEMPLATE_PARAMS \
	typename R BOOST_PP_COMMA_IF( SGE_FUNCTION_OBJECT_PP_NUM_PARAMS ) \
	BOOST_PP_ENUM_PARAMS( SGE_FUNCTION_OBJECT_PP_NUM_PARAMS, typename T )

#define SGE_FUNCTION_OBJECT_PP_TEMPLATE_ARGS \
	R( BOOST_PP_ENUM_PARAMS( SGE_FUNCTION_OBJECT_PP_NUM_PARAMS, T ) )

#define SGE_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR \
	R operator() ( SGE_FUNCTION_OBJECT_PP_FUNCTION_PARAMS )

#define SGE_FUNCTION_OBJECT_PP_FUNCTION_PARAMS \
	BOOST_PP_ENUM_BINARY_PARAMS( SGE_FUNCTION_OBJECT_PP_NUM_PARAMS, T, t )

#define SGE_FUNCTION_OBJECT_PP_FUNCTION_ARGS \
	BOOST_PP_ENUM_PARAMS( SGE_FUNCTION_OBJECT_PP_NUM_PARAMS, t )

namespace sge
{
namespace function
{
namespace detail
{

template< typename F, SGE_FUNCTION_OBJECT_PP_TEMPLATE_PARAMS >
struct functor_wrapper< F, SGE_FUNCTION_OBJECT_PP_TEMPLATE_ARGS >
{
	functor_wrapper( F &f )
		: f_( f )
	{}

	SGE_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR
	{
		return static_cast<R>( f_( SGE_FUNCTION_OBJECT_PP_FUNCTION_ARGS ) );
	}
	
	SGE_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR const
	{
		return static_cast<R>( f_( SGE_FUNCTION_OBJECT_PP_FUNCTION_ARGS ) );
	}

	private:
		F &f_;
};

} // end namespace detail

} // end namespace function

} // end namespace sge

#undef SGE_FUNCTION_OBJECT_PP_TEMPLATE_PARAMS
#undef SGE_FUNCTION_OBJECT_PP_TEMPLATE_ARGS
#undef SGE_FUNCTION_OBJECT_PP_FUNCTION_PARAMS
#undef SGE_FUNCTION_OBJECT_PP_FUNCTION_ARGS
#undef SGE_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR
