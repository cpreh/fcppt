//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_ITERATOR_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_ITERATOR_HPP_INCLUDED

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

namespace fcppt
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
