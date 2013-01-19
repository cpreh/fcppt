//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_DETAIL_ITERATOR_BASE_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_DETAIL_ITERATOR_BASE_HPP_INCLUDED

#include <fcppt/container/tree/iterator_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/mpl/if.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{
namespace detail
{

template<
	typename It
>
struct iterator_base
{
private:
	typedef std::iterator_traits<
		It
	> traits;

	typedef typename traits::value_type::element_type element_type;
public:
	typedef boost::iterator_facade<
		fcppt::container::tree::iterator<
			It
		>,
		element_type,
		typename traits::iterator_category,
		typename boost::mpl::if_<
			std::is_const<
				typename std::remove_reference<
					typename traits::reference
				>::type
			>,
			element_type const &,
			element_type &
		>::type,
		typename traits::difference_type
	> type;
};

}
}
}
}

#endif
