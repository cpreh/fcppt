//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_ITERATOR_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_ITERATOR_HPP_INCLUDED

#include <fcppt/type_traits/detail/is_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/bool.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Checks if a type is an iterator

\ingroup fcppttypetraits

Checks if \a Type is an iterator. If \a Type is a pointer, then the result is
true. Otherwise, \a Type is checked for nested iterator typedefs:
<code>value_type, reference, pointer, difference_type,
iterator_category</code>.

\tparam Type Can be any type
*/
template<
	typename Type
>
using is_iterator
=
boost::mpl::bool_<
	fcppt::type_traits::detail::is_iterator<
		Type
	>::value
>;

}
}

#endif
