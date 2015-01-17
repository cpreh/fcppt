//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_CYCLIC_ITERATOR_BASE_HPP_INCLUDED
#define FCPPT_DETAIL_CYCLIC_ITERATOR_BASE_HPP_INCLUDED

#include <fcppt/cyclic_iterator_fwd.hpp>
#include <fcppt/detail/cyclic_iterator_category.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace detail
{

template<
	typename ContainerIterator
>
struct cyclic_iterator_base
{
	typedef boost::iterator_facade<
		fcppt::cyclic_iterator<
			ContainerIterator
		>,
		typename std::iterator_traits<
			ContainerIterator
		>::value_type,
		typename fcppt::detail::cyclic_iterator_category<
			typename std::iterator_traits<
				ContainerIterator
			>::iterator_category
		>::type,
		typename std::iterator_traits<
			ContainerIterator
		>::reference
	> type;
};

}
}

#endif
