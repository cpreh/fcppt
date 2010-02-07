//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FUNCTION_DETAIL_FUNCTOR_WRAPPER_HPP_INCLUDED
#error "This file is not a standalone header. #include <fcppt/function/detail/functor_wrapper.hpp> instead."
#endif

#ifndef FCPPT_FUNCTION_DETAIL_FUNCTOR_WRAPPER_TEMPLATE_HPP_INCLUDED
#define FCPPT_FUNCTION_DETAIL_FUNCTOR_WRAPPER_TEMPLATE_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>

#endif

#define FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_PARAMS \
	typename R BOOST_PP_COMMA_IF( FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS ) \
	BOOST_PP_ENUM_PARAMS( FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS, typename T )

#define FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_ARGS \
	R( BOOST_PP_ENUM_PARAMS( FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS, T ) )

#define FCPPT_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR \
	R operator() ( FCPPT_FUNCTION_OBJECT_PP_FUNCTION_PARAMS )

#define FCPPT_FUNCTION_OBJECT_PP_FUNCTION_PARAMS \
	BOOST_PP_ENUM_BINARY_PARAMS( FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS, T, t )

#define FCPPT_FUNCTION_OBJECT_PP_FUNCTION_ARGS \
	BOOST_PP_ENUM_PARAMS( FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS, t )

namespace fcppt 
{
namespace function
{
namespace detail
{

template< typename F, FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_PARAMS >
struct functor_wrapper< F, FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_ARGS >
{
	FCPPT_NONASSIGNABLE(functor_wrapper)
public:
	functor_wrapper( F &f )
		: f_( f )
	{}

	FCPPT_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR
	{
		return static_cast<R>( f_( FCPPT_FUNCTION_OBJECT_PP_FUNCTION_ARGS ) );
	}
	
	FCPPT_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR const
	{
		return static_cast<R>( f_( FCPPT_FUNCTION_OBJECT_PP_FUNCTION_ARGS ) );
	}

	private:
		F &f_;
};

} // end namespace detail

} // end namespace function

} // end namespace fcppt 

#undef FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_PARAMS
#undef FCPPT_FUNCTION_OBJECT_PP_TEMPLATE_ARGS
#undef FCPPT_FUNCTION_OBJECT_PP_FUNCTION_PARAMS
#undef FCPPT_FUNCTION_OBJECT_PP_FUNCTION_ARGS
#undef FCPPT_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR
