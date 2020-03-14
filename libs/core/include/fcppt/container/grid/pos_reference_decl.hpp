//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_REFERENCE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REFERENCE_DECL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/pos_reference_fwd.hpp>
#include <fcppt/container/grid/pos_type.hpp>
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
\brief A reference to a grid cell and its position

\ingroup fcpptcontainergrid
*/
template<
	typename Grid
>
class pos_reference
{
public:
	using
	pos_type
	=
	fcppt::container::grid::pos_type<
		std::remove_cv_t<
			Grid
		>
	>;

	using
	reference
	=
	fcppt::container::to_reference_type<
		Grid
	>;

	pos_reference(
		pos_type,
		reference
	);

	[[nodiscard]]
	pos_type const &
	pos() const;

	[[nodiscard]]
	reference
	value() const;
private:
	pos_type pos_;

	fcppt::reference<
		std::remove_reference_t<
			reference
		>
	> value_;
};

}
}
}

#endif
