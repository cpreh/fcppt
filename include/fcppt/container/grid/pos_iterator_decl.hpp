//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/object_decl.hpp>
#include <fcppt/container/grid/pos_iterator_fwd.hpp>
#include <fcppt/container/grid/detail/pos_iterator_base.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/mpl/if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Grid
>
class pos_iterator
:
	public
	fcppt::container::grid::detail::pos_iterator_base<
		Grid
	>::type
{
	typedef
	typename
	fcppt::container::grid::detail::pos_iterator_base<
		Grid
	>::type
	base_type;

	typedef
	typename
	Grid::dim
	dim;

	typedef
	typename
	boost::mpl::if_<
		std::is_const<
			Grid
		>,
		typename
		Grid::const_iterator,
		typename
		Grid::iterator
	>::type
	iterator;
public:
	typedef
	typename
	base_type::value_type
	value_type;

	typedef
	typename
	base_type::reference
	reference;

	typedef
	typename
	base_type::pointer
	pointer;

	typedef
	typename
	base_type::iterator_category
	iterator_category;

	typedef
	typename
	base_type::difference_type
	difference_type;

	pos_iterator(
		iterator const &,
		dim const &size,
		dim const &pos,
		dim const &min,
		dim const &max,
		bool is_end
	);
private:
	friend class boost::iterator_core_access;

	void
	increment();

	reference
	dereference() const;

	bool
	equal(
		pos_iterator const &
	) const;

	iterator iterator_;

	dim size_;

	dim pos_;

	dim min_;

	dim max_;

	bool is_end_;
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
