//  Copyright Thomas Heller 2009 - 2010.
//  Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FUNCTION_OBJECT_HPP_INCLUDED
#define FCPPT_FUNCTION_OBJECT_HPP_INCLUDED

#include <fcppt/function/object_fwd.hpp>
#include <fcppt/function/detail/clear_type.hpp>
// this include needs to be here to stop the cpp from bitching around
#include <fcppt/function/detail/functor_wrapper.hpp>

namespace fcppt
{

namespace function
{

template< typename Signature >
bool operator== ( const object<Signature>& f, detail::clear_type* )
{
	return !f;
}

template< typename Signature >
bool operator== ( detail::clear_type*, const object<Signature>& f )
{
	return !f;
}

template< typename Signature >
bool operator!= ( const object<Signature>& f, detail::clear_type* )
{
	return f;
}

template< typename Signature >
bool operator!= ( detail::clear_type*, const object<Signature>& f )
{
	return f;
}

template< typename Signature >
void swap( object<Signature>& x, object<Signature>& y )
{
	x.swap( y );
}

} // end namespace function

} // end namespace fcppt

// \cond FCPPT_DOXYGEN_DEBUG
#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 0
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 1
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 2
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 3
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 4
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 5
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 6
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 7
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 8
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 9
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 10
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 11
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 12
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 13
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 14
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 15
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 16
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 17
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 18
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 19
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 20
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 21
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 22
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 23
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 24
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 25
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 26
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 27
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS

#define FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS 28
#include <fcppt/function/impl/object_template.hpp>
#undef FCPPT_FUNCTION_OBJECT_PP_NUM_PARAMS
// \endcond

/**
 * variadic template version ...
 *
template< typename R, typename... Args  >
struct object< R( Args... ) >
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

		typedef typename std::tr1::function< R( Args... ) > function_type;
		typedef R return_type;

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
			: function_( detail::functor_wrapper< F, R( Args... ) >( f ) )
		{}

		object& operator=( const object& other )
		{
			object( other ).swap( *this );
			return *this;
		}

		object& operator= ( clear_type* c )
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
							R( Args... )
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

		operator safe_bool_() const
		{
			if( function_ )
				return &hidden_type_::m_bool_;
			else
				return 0;
		}

		R operator() ( Args... args )
		{
			return function_( args... );
		}

		R operator() ( Args... args ) const
		{
			return function_( args... );
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
*/

#endif
