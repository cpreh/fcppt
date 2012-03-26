//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_RANDOM_ACCESS_ITERATOR_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_RANDOM_ACCESS_ITERATOR_HPP_INCLUDED

#include <fcppt/type_traits/is_iterator_of_category.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace type_traits
{

/**

\ingroup fcppttypetraits

*/
template<
	typename T
>
struct is_random_access_iterator
:
fcppt::type_traits::is_iterator_of_category<
	T,
	std::random_access_iterator_tag
>
{
};

}
}

#endif
