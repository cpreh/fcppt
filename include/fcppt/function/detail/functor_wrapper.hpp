
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
#define SGE_FUNCTION_DETAIL_FUNCTOR_WRAPPER_HPP_INCLUDED

#include <sge/function/detail/functor_wrapper_fwd.hpp>

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 0
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 1
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 2
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 3
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 4
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 5
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 6
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 7
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 8
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 9
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 10
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 11
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 12
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 13
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 14
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 15
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 16
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 17
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 18
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 19
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 20
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 21
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 22
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 23
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 24
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 25
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 26
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 27
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

#define SGE_FUNCTION_OBJECT_PP_NUM_PARAMS 28
#include <sge/function/detail/functor_wrapper_template.ipp>
#undef SGE_FUNCTION_OBJECT_PP_NUM_PARAMS

/**
 * variadic template version ...
 *

template< typename F, typename... Args >
struct functor_wrapper< F, R( Args... ) >
{
	functor_wrapper( F &f )
		: f_( f )
	{}

	R operator( Args... args )
	{
		return static_cast<R>( f_( args... ) );
	}

	R operator( Args... args ) const
	{
		return static_cast<R>( f_( args...)  );
	}

	private:
		F &f_;
};
*/

#endif
