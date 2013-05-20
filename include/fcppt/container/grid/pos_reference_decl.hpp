//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_REFERENCE_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REFERENCE_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/container/grid/pos_reference_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

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
	Grid::dim
	dim;

	typedef
	typename
	boost::mpl::if_<
		std::is_const<
			Grid
		>,
		typename
		Grid::const_reference,
		typename
		Grid::reference
	>::type
	reference;

	pos_reference(
		dim const &,
		reference
	);

	dim const &
	pos() const;

	reference
	value() const;
private:
	dim const pos_;

	reference value_;
};

}
}
}

#endif
