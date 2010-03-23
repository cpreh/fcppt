//  Copyright Thomas Heller 2009 - 2010.
//  Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FUNCTION_DETAIL_HAS_ADDRESSOF_OVERLOAD_HPP_INCLUDED
#define FCPPT_FUNCTION_DETAIL_HAS_ADDRESSOF_OVERLOAD_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_class.hpp>
#include <boost/mpl/bool.hpp>

namespace fcppt
{

namespace function
{

namespace detail
{

template< typename func, typename U = void >
struct has_addressof_overload;

template< typename func >
struct has_addressof_overload
<
   func,
   typename boost::enable_if< boost::is_class<func> >::type
>
{
   //private:
      typedef char one;
      typedef struct { char a[2]; } two;

      template< typename T >
      static one test( T* );

      template< typename T >
      static two test( ... );

      static func f;

   //public:
      enum
      {
         value = ( sizeof( test<func>( &f ) ) == sizeof( two ) )
      };

      typedef boost::mpl::bool_<value> type;

      //enum { value = true };
};

template< typename func >
struct has_addressof_overload
<
   func,
   typename boost::disable_if< boost::is_class<func> >::type
>
{
   enum { value = false };

   typedef boost::mpl::bool_<false> type;
};

} // end namespace detail

} // end namespace function

} // end namespace fcppt

#endif
