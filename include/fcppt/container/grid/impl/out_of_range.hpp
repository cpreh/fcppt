//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_IMPL_OUT_OF_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_IMPL_OUT_OF_RANGE_HPP_INCLUDED

#include <fcppt/text.hpp>

inline
fcppt::container::grid::out_of_range::out_of_range()
:
	fcppt::container::grid::exception(
		FCPPT_TEXT("grid::at() out of range!")
	)
{}

#endif
