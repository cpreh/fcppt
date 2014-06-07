//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_CYCLIC_ITERATOR_CATEGORY_HPP_INCLUDED
#define FCPPT_DETAIL_CYCLIC_ITERATOR_CATEGORY_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace detail
{

template<
	typename SourceCategory
>
struct cyclic_iterator_category;

template<>
struct cyclic_iterator_category<
	std::forward_iterator_tag
>
{
	typedef std::forward_iterator_tag type;
};

template<>
struct cyclic_iterator_category<
	std::bidirectional_iterator_tag
>
{
	typedef std::bidirectional_iterator_tag type;
};

template<>
struct cyclic_iterator_category<
	std::random_access_iterator_tag
>
{
	typedef std::bidirectional_iterator_tag type;
};

}
}

#endif
