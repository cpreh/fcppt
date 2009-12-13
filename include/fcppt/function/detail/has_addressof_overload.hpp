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


#ifndef SGE_FUNCTION_DETAIL_HAS_ADDRESSOF_OVERLOAD_HPP_INCLUDED
#define SGE_FUNCTION_DETAIL_HAS_ADDRESSOF_OVERLOAD_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_class.hpp>
#include <boost/mpl/bool.hpp>

namespace sge
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

} // end namespace sge

#endif
