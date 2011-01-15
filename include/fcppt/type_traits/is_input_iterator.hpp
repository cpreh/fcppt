//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_INPUT_ITERATOR_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_INPUT_ITERATOR_HPP_INCLUDED

#include <boost/type_traits/is_same.hpp>
#include <iterator>

namespace fcppt
{
namespace type_traits
{

template<
	typename T
>
struct is_input_iterator
:
boost::is_same<
	typename std::iterator_traits<
		T
	>::iterator_category,
	std::input_iterator_tag
>
{
};

}
}

#endif
