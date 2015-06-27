//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/container/grid/min.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_iterator_fwd.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/sup.hpp>
#include <fcppt/container/grid/detail/pos_iterator_base.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
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
	typename SizeType,
	fcppt::container::grid::size_type Size
>
class pos_iterator final
:
	public
		fcppt::container::grid::detail::pos_iterator_base<
			SizeType,
			Size
		>
{
	typedef
	fcppt::container::grid::detail::pos_iterator_base<
		SizeType,
		Size
	>
	base_type;
public:
	typedef
	typename
	base_type::value_type
	value_type;

	typedef
	value_type
	pos;

	typedef
	typename
	pos::value_type
	size_type;

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

	typedef
	fcppt::container::grid::min<
		size_type,
		Size
	>
	min;

	typedef
	fcppt::container::grid::sup<
		size_type,
		Size
	>
	sup;

	pos_iterator(
		pos,
		min,
		sup
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

	pos current_;

	min min_;

	sup sup_;
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
