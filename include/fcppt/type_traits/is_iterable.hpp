//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_ITERABLE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_ITERABLE_HPP_INCLUDED

#include <fcppt/type_traits/has_iterator.hpp>
#include <fcppt/type_traits/has_const_iterator.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/mpl/if.hpp>

namespace fcppt
{
namespace type_traits
{
template<typename T>
struct is_iterable
{
public:
	static bool const value = 
		boost::mpl::if_
		<
			boost::is_const<T>,
			has_const_iterator<T>,
			has_iterator<T>
		>::type::value;
};
}
}

#endif
