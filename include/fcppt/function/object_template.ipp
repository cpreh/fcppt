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


#ifndef SGE_FUNCTION_OBJECT_HPP_INCLUDED
#error "This file is not a standalone header. #include <sge/function/object.hpp> instead."
#endif

#ifndef SGE_FUNCTION_OBJECT_TEMPLATE_HPP_INCLUDED
#define SGE_FUNCTION_OBJECT_TEMPLATE_HPP_INCLUDED

#include <sge/function/detail/has_addressof_overload.hpp>
#include <sge/function/detail/clear_type.hpp>
// this include leads to a cpp fail ...
//#include <sge/function/detail/functor_wrapper.hpp>

#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_class.hpp>

#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>

#include <tr1/functional>
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

template< SGE_FUNCTION_OBJECT_PP_TEMPLATE_PARAMS  >
class object< SGE_FUNCTION_OBJECT_PP_TEMPLATE_ARGS >
{
	private:
		/// This class is used to implement the safe_bool idiom.
		struct hidden_type
		{
			hidden_type* bool_;
		};

		/// This typedef is used to implement the safe_bool idiom.
		typedef hidden_type* hidden_type::* safe_bool;

		struct useless {};

	public:

		typedef typename std::tr1::function< SGE_FUNCTION_OBJECT_PP_TEMPLATE_ARGS > function_type;
		typedef R result_type;

		object()
		{}

		object( detail::clear_type* )
		{}

		object( const object& other )
			: function_( other.function_ )
		{}
		
		// constructor for functors without operator& overload, and regular functions
		template< typename F >
		object
			(
				F f,
				typename boost::enable_if
					<
						boost::mpl::not_
							<
								detail::has_addressof_overload< F >
							>,
						useless
					>::type = useless()
			)
			: function_( f )
		{}

		// constructor for functors with operator& overload
		template< typename F >
		object
			(
				F f,
				typename boost::enable_if
					<
						boost::mpl::and_
							<
								boost::is_class< F >,
								detail::has_addressof_overload< F >
							>,
						useless
					>::type = useless()
			)
			: function_( detail::functor_wrapper< F, SGE_FUNCTION_OBJECT_PP_TEMPLATE_ARGS >( f ) )
		{}

		object& operator= ( const object& other )
		{
			object( other ).swap( *this );
			return *this;
		}

		object& operator= ( detail::clear_type* c )
		{
			function_ = c;

			return *this;
		}
		
		// assignment operator for functors without operator& overload, and regular functions
		template< typename F >
		typename boost::enable_if
			<
				boost::mpl::not_
					<
						detail::has_addressof_overload< F >
					>,
				object&
			>::type operator= ( F f	)
		{
			object( f ).swap( *this );
			return *this;
		}

		// assignment operator for functors with operator& overload
		template< typename F >
		typename boost::enable_if
			<
				boost::mpl::and_
					<
						boost::is_class< F >,
						detail::has_addressof_overload< F >
					>,
				object&
			>::type operator= ( F f )
		{
			object
				(
					detail::functor_wrapper
						<
							F,
							SGE_FUNCTION_OBJECT_PP_TEMPLATE_ARGS
						>( f )
				).swap( *this );

			return *this;
		}

		void swap( object& other )
		{
			function_type tmp = function_;
			function_ = other.function_;
			other.function_ = tmp;
		}

		operator safe_bool() const
		{
			if( function_ )
				return &hidden_type::bool_;
			else
				return 0;
		}

		SGE_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR
		{
			return function_( SGE_FUNCTION_OBJECT_PP_FUNCTION_ARGS );
		}
		
		SGE_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR const
		{
			return function_( SGE_FUNCTION_OBJECT_PP_FUNCTION_ARGS );
		}

		const std::type_info& target_type() const
		{
			return function_.target_type();
		}

		template< typename F >
		F* target()
		{
			return function_.target<F>();
		}
		
		template< typename F >
		const F* target() const
		{
			return function_.target<F>();
		}

	private:

		template< typename F >
		void operator==( const object<F>& ) const;
		
		template< typename F >
		void operator!=( const object<F>& ) const;

		function_type function_;
};

} // end namespace function

} // end namespace sge

#undef SGE_FUNCTION_OBJECT_PP_TEMPLATE_PARAMS
#undef SGE_FUNCTION_OBJECT_PP_TEMPLATE_ARGS
#undef SGE_FUNCTION_OBJECT_PP_FUNCTION_PARAMS
#undef SGE_FUNCTION_OBJECT_PP_FUNCTION_ARGS
#undef SGE_FUNCTION_OBJECT_PP_FUNCTION_OPERATOR
