//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_REFERENCE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REFERENCE_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_reference_fwd.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief A reference to a grid cell and its position

\ingroup fcpptcontainergrid
*/
template<
	typename Grid
>
class pos_reference
{
	FCPPT_NONASSIGNABLE(
		pos_reference
	);
public:
	typedef
	typename
	Grid::pos
	pos_type;

	typedef
	fcppt::container::to_reference_type<
		Grid
	>
	reference;

	pos_reference(
		pos_type const &,
		reference
	);

	pos_type const &
	pos() const;

	reference
	value() const;
private:
	pos_type const pos_;

	reference value_;
};

}
}
}

#endif
