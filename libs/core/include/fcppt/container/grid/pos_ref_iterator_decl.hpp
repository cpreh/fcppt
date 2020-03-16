//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_REF_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REF_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/dim_type.hpp>
#include <fcppt/container/grid/object_decl.hpp>
#include <fcppt/container/grid/pos_iterator_impl.hpp>
#include <fcppt/container/grid/pos_ref_iterator_fwd.hpp>
#include <fcppt/container/grid/pos_type.hpp>
#include <fcppt/container/grid/detail/pos_ref_iterator_base.hpp>
#include <fcppt/iterator/base_decl.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

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
	using
	base_type
	=
	fcppt::container::grid::detail::pos_ref_iterator_base<
		Grid
	>;

	using
	dim
	=
	fcppt::container::grid::dim_type<
		std::remove_cv_t<
			Grid
		>
	>;

	using
	pos
	=
	fcppt::container::grid::pos_type<
		std::remove_cv_t<
			Grid
		>
	>;

	using
	iterator
	=
	fcppt::container::to_iterator_type<
		Grid
	>;
public:
	using
	value_type
	=
	fcppt::type_traits::value_type<
		base_type
	>;

	using
	reference
	=
	typename
	base_type::reference;

	using
	pointer
	=
	typename
	base_type::pointer;

	using
	iterator_category
	=
	typename
	base_type::iterator_category;

	using
	difference_type
	=
	typename
	base_type::difference_type;

	using
	pos_iterator
	=
	fcppt::container::grid::pos_iterator<
		fcppt::type_traits::value_type<
			pos
		>,
		pos::static_size::value
	>;

	pos_ref_iterator(
		iterator,
		pos_iterator,
		dim
	);

	void
	increment();

	[[nodiscard]]
	reference
	dereference() const;

	[[nodiscard]]
	bool
	equal(
		pos_ref_iterator const &
	) const;
private:
	iterator iterator_;

	pos_iterator pos_iterator_;

	dim size_;
};

}
}
}

#endif
