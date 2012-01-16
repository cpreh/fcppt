//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_ITERATOR_OF_CATEGORY_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_ITERATOR_OF_CATEGORY_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace type_traits
{

template<
	typename T,
	typename Category
>
struct is_iterator_of_category
:
boost::is_base_of<
	Category,
	typename std::iterator_traits<
		T
	>::iterator_category
>
{
};

}
}

#endif
