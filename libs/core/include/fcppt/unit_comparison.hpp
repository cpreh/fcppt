//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UNIT_COMPARISON_HPP_INCLUDED
#define FCPPT_UNIT_COMPARISON_HPP_INCLUDED

#include <fcppt/unit_fwd.hpp>


namespace fcppt
{

/**
\brief Compares units for equality.

\ingroup fcpptvarious
*/
inline
bool
operator==(
	fcppt::unit const &,
	fcppt::unit const &
)
{
	return
		true;
}

/**
\brief Compares units for inequality.

\ingroup fcpptvarious
*/
inline
bool
operator!=(
	fcppt::unit const &,
	fcppt::unit const &
)
{
	return
		false;
}

}

#endif
