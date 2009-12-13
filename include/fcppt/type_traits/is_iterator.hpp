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


#ifndef SGE_TYPE_TRAITS_IS_ITERATOR_HPP_INCLUDED
#define SGE_TYPE_TRAITS_IS_ITERATOR_HPP_INCLUDED

#include <boost/type_traits/integral_constant.hpp>
#include <iterator>

namespace boost
{

template<
	typename T,
	typename I,
	typename R,
	typename V
>
class transform_iterator;

}

namespace sge
{
namespace type_traits
{

template<
	typename  T
>
class is_iterator
:
public boost::false_type
{};

template<
	typename T,
	typename U,
	typename V,
	typename W,
	typename X
>
class is_iterator<
	std::iterator<T,U,V,W,X>
>
:
public boost::true_type
{};

template<
	typename U,
	typename I,
	typename R,
	typename V
>
class is_iterator<
	boost::transform_iterator<U, I, R, V>
>
:
public boost::true_type
{};

template<
	typename T
>
class is_iterator<T *>
:
public boost::true_type
{};

}
}

#endif
