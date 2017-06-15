//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_REF_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REF_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/object_decl.hpp>
#include <fcppt/container/grid/pos_iterator_impl.hpp>
#include <fcppt/container/grid/pos_ref_iterator_fwd.hpp>
#include <fcppt/container/grid/detail/pos_ref_iterator_base.hpp>
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

/**
\brief An iterator over grid references

\ingroup fcpptcontainergrid
*/
template<
	typename Grid
>
class pos_ref_iterator final
:
	public
		fcppt::container::grid::detail::pos_ref_iterator_base<
			Grid
		>
{
	typedef
	fcppt::container::grid::detail::pos_ref_iterator_base<
		Grid
	>
	base_type;

	typedef
	typename
	Grid::dim
	dim;

	typedef
	typename
	Grid::pos
	pos;

	typedef
	fcppt::container::to_iterator_type<
		Grid
	>
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

	typedef
	fcppt::container::grid::pos_iterator<
		typename
		pos::value_type,
		pos::static_size::value
	>
	pos_iterator;

	pos_ref_iterator(
		iterator const &,
		pos_iterator const &,
		dim
	);
private:
	friend class boost::iterator_core_access;

	void
	increment();

	reference
	dereference() const;

	bool
	equal(
		pos_ref_iterator const &
	) const;

	iterator iterator_;

	pos_iterator pos_iterator_;

	dim size_;
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
